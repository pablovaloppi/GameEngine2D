#pragma once
#include <string>
#include <map>

class GameObject
{
public:
	GameObject();
	~GameObject();

	void setName(std::string name);
	std::string getName();


private:
	std::string m_name;
};

