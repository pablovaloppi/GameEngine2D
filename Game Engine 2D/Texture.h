#pragma once
#include <GL\glew.h>

#include "MsgError.h"

class Texture
{
public:
	Texture();
	~Texture();

	void create(GLchar *pathTexture);
	void getTexture();

private:
	GLuint m_textureID;
	GLint m_width, m_heigth;
};

