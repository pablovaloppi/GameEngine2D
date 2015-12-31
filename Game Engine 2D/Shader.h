#pragma once
#include <GL\glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

class Shader
{
public:
	Shader();
	~Shader();
	
	void create(std::string vertexPath, std::string fragmentPath);
	void use();
	GLuint getProgram();
private:
	void loadShader(std::string path, GLenum typeShader);
	void createProgram();

	GLuint vertex, fragment, program;
};

