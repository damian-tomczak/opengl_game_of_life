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
    for (GameObject& tile : this->Cells)
            tile.Draw(renderer);
}

bool GameLevel::IsCompleted()
{
    for (GameObject& tile : this->Cells)
        return true;
}

void GameLevel::init(std::vector<std::vector<unsigned int>> tileData, unsigned int levelWidth, unsigned int levelHeight)
{

    unsigned int height = tileData.size();
    unsigned int width = tileData[0].size(); 
    float unit_width = levelWidth / static_cast<float>(width), unit_height = levelHeight / height;
	
    for (unsigned int y = 0; y < height; ++y)
    {
        for (unsigned int x = 0; x < width; ++x)
        {

            if (tileData[y][x] == 1) 
            {
                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                Cell obj(pos, size, true, 0);
                this->Cells.push_back(obj);
            }
            else if (tileData[y][x] > 1)
            {
                glm::vec3 color = glm::vec3(1.0f); 
                if (tileData[y][x] == 2)
                    color = glm::vec3(0.2f, 0.6f, 1.0f);
                else if (tileData[y][x] == 3)
                    color = glm::vec3(0.0f, 0.7f, 0.0f);
                else if (tileData[y][x] == 4)
                    color = glm::vec3(0.8f, 0.8f, 0.4f);
                else if (tileData[y][x] == 5)
                    color = glm::vec3(1.0f, 0.5f, 0.0f);

                glm::vec2 pos(unit_width * x, unit_height * y);
                glm::vec2 size(unit_width, unit_height);
                this->Cells.push_back(Cell(pos, size, true, 0));
            }
        }
    }
}