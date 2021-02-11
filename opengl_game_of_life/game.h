#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "resource_manager.h"

enum GameState {
	GAME_ACTIVE,
	GAME_INACTIVE
};

class Game
{
public:
	GameState State;
	bool  Keys[1024];
	unsigned int Width, Height;
	Game(unsigned int width, unsigned int height);
	~Game();

	void Init();

	void ProcessInput(float dt);
	void Update(float dt);
	void Render();
};

