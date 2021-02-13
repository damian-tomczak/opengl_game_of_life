#pragma once
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <fstream>
#include <sstream>
#include <vector>

#include "game_object.h"
#include "sprite_renderer.h"
#include "resource_manager.h"
#include "cell.h"

class GameLevel
{
public:

    std::vector<std::vector<Cell>> Cells;

    GameLevel() { }

    void Load(unsigned int levelWidth, unsigned int levelHeight);

    void Refresh();

    void Draw(SpriteRenderer& renderer);
private:

    void init(std::vector<std::vector<unsigned int>> cellData, unsigned int levelWidth, unsigned int levelHeight);
};
