#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::setName(std::string name)
{
	this->m_name = name;
}

std::string GameObject::getName()
{
	return this->m_name;
}
