#pragma once

#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Scene.h"

using glm::vec3;
using glm::mat4;

class Transform
{
public:
	Transform();
	~Transform();

	void SetPosition(vec3 position);
	vec3 GetPosition();
	void SetAngleRotation(float rotation);
	float GetAngleRotation();
	void SetScale(vec3 scale);
	vec3 GetScale();

	void Translate(vec3 newPosition);

private:
	vec3 m_position;
	float m_angleRotation;
	vec3 m_scale;
	
	mat4 m_model;
	mat4 m_view;
	mat4 m_projection;
};

