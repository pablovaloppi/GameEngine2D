#pragma once

#include <Window.h>
#include <Input.h>
#include <Shader.h>
#include <Sprite.h>
#include <Scene.h>

class MainGame
{
public:
	MainGame();
	~MainGame();

	void Init();
	void Update();
	void Draw();
	void Run();

private:
	Window m_Window;
	Input m_Input;
	Shader m_shader;
	Sprite m_sprite;
	Sprite m_sprite2;
	Scene m_scene;

	bool m_gameState;
};

