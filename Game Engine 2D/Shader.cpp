#include "Shader.h"
#include "MsgError.h"

Shader::Shader(): vertex(0), fragment(0), program(0)
{
}

Shader::~Shader()
{
}

void Shader::create(std::string vertexPath, std::string fragmentPath)
{
	loadShader(vertexPath, GL_VERTEX_SHADER);
	loadShader(fragmentPath, GL_FRAGMENT_SHADER);
	createProgram();
}

void Shader::use()
{
	glUseProgram(this->program);
}

GLuint Shader::getProgram()
{
	return this->program;
}

void Shader::loadShader(std::string path, GLenum typeShader)
{
	std::ifstream shader(path);
	if (!shader.is_open())
	{
		msgError("Error: No se pudo abrir el archivo:", path);
	}
	std::stringstream shaderStream;
	std::string shaderFile;

	shaderStream << shader.rdbuf();

	shader.close();

	shaderFile = shaderStream.str();

	const GLchar *shaderCode = shaderFile.c_str();

	GLint succes;
	char infolog[512];


	if (typeShader == GL_VERTEX_SHADER)
	{
		vertex = glCreateShader(typeShader);
		glShaderSource(vertex, 1, &shaderCode, NULL);
		glCompileShader(vertex);
		
		glGetShaderiv(vertex, GL_COMPILE_STATUS, &succes);

		if (!succes)
		{
			glGetShaderInfoLog(vertex, 512, NULL, infolog);
			msgError("Error: Vertex shader error de compilacion:", infolog);
		}
	}	

	else if (typeShader == GL_FRAGMENT_SHADER)
	{
		fragment = glCreateShader(typeShader);
		glShaderSource(fragment, 1, &shaderCode, NULL);
		glCompileShader(fragment);

		glGetShaderiv(fragment, GL_COMPILE_STATUS, &succes);

		if (!succes)
		{
			glGetShaderInfoLog(fragment, 512, NULL, infolog);
			msgError("Error: Fragment shader error de compilacion:", infolog);
		}
	}

}

void Shader::createProgram()
{
	program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);

	GLint succes;
	char infolog[512];

	glGetProgramiv(program, GL_LINK_STATUS, &succes);
	if (!succes)
	{
		glGetProgramInfoLog(program, 512, NULL, infolog);
		msgError("Error: Program shader fallo en la vinculacion:", infolog);
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}
