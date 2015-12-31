#include <GameEngine2D.h>

#include "MainGame.h"

MainGame::MainGame() : m_gameState(true)
{
	
}


MainGame::~MainGame()
{
}

void MainGame::Init()
{
	GameEngine2D::Init();
	m_Window.createWindow("PingPong", 600, 800, NORMAL);

	m_shader.create("Shaders/default.vert", "Shaders/default.frag");


	m_sprite.create(0.0, 0.0, 0.5, 0.5, "Textures/imagen.png");
	m_sprite2.create(-1.0, -1.0, 0.5, 0.5, "Textures/2.png");
	
}

void MainGame::Update()
{
	while (m_gameState)
	{
		m_gameState = m_Input.processEvent();

		Draw();

		m_Window.swapBuffers();
	}
}

void MainGame::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	m_sprite.draw();
	m_sprite2.draw();

}

void MainGame::Run()
{
	Init();
	Update();
}