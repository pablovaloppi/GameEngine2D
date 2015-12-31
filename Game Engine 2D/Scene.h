#pragma once
#include "Shader.h"

class Scene
{
public:
	Scene();
	~Scene();

	static Shader GetDefaultShader();
	void SetDefaultShader(Shader shader);



	static Shader m_shader;
};

