#include "Texture.h"
#include <SOIL.h>


Texture::Texture(): m_textureID(0), m_heigth(0), m_width(0)
{	
}


Texture::~Texture()
{
}

void Texture::create(GLchar *pathTexture)
{
	
	glGenTextures(1, &m_textureID);
	glBindTexture(GL_TEXTURE_2D, m_textureID);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	unsigned char *image = SOIL_load_image(pathTexture, &m_width, &m_heigth, 0, SOIL_LOAD_RGBA);
	if (image == nullptr)
	{
		msgError("Error: No se pudo abrir la textura:", pathTexture);
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::getTexture()
{
	glBindTexture(GL_TEXTURE_2D, this->m_textureID);
}
