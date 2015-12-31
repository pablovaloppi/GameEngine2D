#pragma once

#include <GL\glew.h>
#include <SDL\SDL.h>

enum TypeWindow{NORMAL, FULLSCREEN};

class Window
{
public:
	Window();
	~Window();

	// Functions
	void createWindow(GLchar *title, GLint height, GLint width, TypeWindow type);
	void swapBuffers();
private:
	

	// Variables
	SDL_Window *m_window;
	SDL_GLContext context;
	GLint m_height, m_width;
	GLchar *m_title;
	TypeWindow m_type;
};
