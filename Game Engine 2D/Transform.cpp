#include "Transform.h"



Transform::Transform() : m_position(vec3(0)), m_angleRotation(0), m_scale(1), m_model(mat4()), m_view(mat4()), m_projection(mat4())
{
}


Transform::~Transform()
{
}

void Transform::SetPosition(vec3 position)
{
	this->m_position = position;
}

vec3 Transform::GetPosition()
{
	return this->m_position;
}

void Transform::SetAngleRotation(float rotation)
{
	this->m_angleRotation = rotation;
}

float Transform::GetAngleRotation()
{
	return this->m_angleRotation;
}

void Transform::SetScale(vec3 scale)
{
	this->m_scale = scale;	
}

vec3 Transform::GetScale()
{
	return this->m_scale;
}
