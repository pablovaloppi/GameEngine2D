#include "Sprite.h"



Sprite::Sprite(): m_posX(0), m_posY(0), m_width(0), m_height(0), m_shader(&(Scene::GetDefaultShader()))
{
}


Sprite::~Sprite()
{
}

void Sprite::create(GLfloat posX, GLfloat posY, GLfloat widht, GLfloat height, GLchar *pathTexture)
{
	this->m_posX = posX;
	this->m_posY = posY;
	this->m_width = widht;
	this->m_height = height;

	m_texture.create(pathTexture);

	GLfloat vertices[] = {
		m_posX			, m_posY,				0.0f, 1.0f,
		m_posX + m_width, m_posY,				1.0f, 1.0f, 
		m_posX			, m_posY + m_height,	0.0f, 0.0f,
		m_posX + m_width, m_posY + m_height,	1.0f, 0.0f
	};
	/*
	GLfloat vertices[] = {
		// Positions          // Colors           // Texture Coords
		//0.5f,  0.5f,   1.0f, 1.0f, // Top Right
		0.0f,  0.5f,     0.0f, 1.0f,  // Top Left 
		0.5f, -0.5f,    1.0f, 0.0f, // Bottom Right
	   -0.5f, -0.5f,   0.0f, 0.0f, // Bottom Left
		
	};*/
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);

	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid *)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void Sprite::draw()
{
	m_shader->use();
	glActiveTexture(GL_TEXTURE0);
	m_texture.getTexture();
	glUniform1i(glGetUniformLocation(m_shader->getProgram(), "textura"), 0);
	glBindVertexArray(m_vao);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
}
