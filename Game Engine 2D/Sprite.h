#pragma once
#include <GL\glew.h>

#include "Texture.h"
#include "Shader.h"
#include "Transform.h"
#include "Scene.h"

class Sprite
{
public:
	Sprite();
	~Sprite();

	void create(GLfloat posX, GLfloat posY, GLfloat widht, GLfloat height, GLchar *pathTexture);
	void draw();

	Transform transform;

private:
	GLfloat m_width, m_height;
	GLfloat m_posX, m_posY;
	GLuint m_vbo, m_vao;

	Texture m_texture;

	Shader *m_shader;
};

