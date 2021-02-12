#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <vector>

#include "resource_manager.h"
#include "sprite_renderer.h"
#include "game_level.h"
#include "game_object.h"

enum GameState {
	GAME_ACTIVE,
	GAME_INACTIVE
};

class Game
{
public:
	GameState State;
	GameLevel Level;

	bool  Keys[1024];
	unsigned int Width, Height;
	Game(unsigned int width, unsigned int height);
	~Game();

	void Init();

	void ProcessInput(float dt);
	void Update(float dt);
	void Render();
};

