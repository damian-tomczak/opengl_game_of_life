#include "game_level.h"

std::vector<std::vector<unsigned int>> world;

void GameLevel::Load(unsigned int levelWidth, unsigned int levelHeight)
{

    this->Cells.clear();

    for (int i = 0; i < levelHeight; i++)
    {
        world.push_back(std::vector<unsigned int>());
        for (int j = 0; j < levelWidth; j++)
        {
            world[i].push_back(rand() % 2 + 0);
        }
    }
    
    if (world.size() > 0)
        this->init(world, levelWidth, levelHeight);
}

void GameLevel::Draw(SpriteRenderer& renderer)
{
    for (Cell& tile : this->Cells)
            tile.Draw(renderer);
}

void GameLevel::init(std::vector<std::vector<unsigned int>> cellData, unsigned int levelWidth, unsigned int levelHeight)
{

    unsigned int height = cellData.size();
    unsigned int width = cellData[0].size(); 
    float unit_width = levelWidth / static_cast<float>(width), unit_height = levelHeight / height;
	
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {
            glm::vec2 pos(unit_width * x, unit_height * y);
            glm::vec2 size(unit_width, unit_height);
            bool isLive = false;

            if (cellData[y][x] == 1) 
                isLive = true;
            else
                isLive = false;

            Cell obj(pos, size, isLive, 0);
            this->Cells.push_back(obj);
        }
    }
}