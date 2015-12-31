#include "Window.h"

Window::Window()
{
	
}

Window::~Window()
{
	m_title = nullptr;
	m_height = 0;
	m_width = 0;
	m_window = nullptr;

	SDL_GL_DeleteContext(this->context);
	SDL_DestroyWindow(this->m_window);
	SDL_Quit();
}

void Window::createWindow(GLchar *title, GLint height, GLint width, TypeWindow type)
{
	this->m_title = title;
	this->m_height = height;
	this->m_width = width;
	this->m_type = type;
	

	if (m_type == NORMAL)
	{
		this->m_window = SDL_CreateWindow(this->m_title, 100, 100, m_width, m_height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	}
	else if (m_type == FULLSCREEN)
	{
		this->m_window = SDL_CreateWindow(this->m_title, 100, 100, m_width, m_height, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL);
	}
	
	this->context = SDL_GL_CreateContext(this->m_window);

	SDL_GL_SetSwapInterval(1);
	
	glewInit();

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glViewport(0, 0, this->m_width, this->m_height);

}

void Window::swapBuffers()
{
	SDL_GL_SwapWindow(this->m_window);
}


