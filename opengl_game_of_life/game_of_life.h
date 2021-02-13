#pragma once

#include "cell.h"

void GameOfLife(std::vector<std::vector<Cell>>& world)
{
    for (unsigned int y = 0; y < world.size(); ++y)
    {
        for (unsigned int x = 0; x < world[0].size(); ++x)
        {
            world[y][x].neighbours = 0;
            // left neighbour
            if (x > 0)
            {
                if (world[y][x - 1].isLive == true)
                {
                    world[y][x].neighbours++;
                }
            }

            // right neighbour
            if (x < world[y].size() - 1)
            {
                if (world[y][x + 1].isLive == true)
                {
                    world[y][x].neighbours++;
                }
            }

            // top neighbour
            if (y > 0)
            {
                if (world[y - 1][x].isLive == true)
                {
                    world[y][x].neighbours++;
                }
            }

            // bottom neighbour
            if (y < world.size() - 1)
            {
                if (world[y + 1][x].isLive == true)
                {
                    world[y][x].neighbours++;
                }
            }

            // left-top neighbour
            if (x > 0 && y > 0)
            {
                if (world[y - 1][x - 1].isLive == true)
                {
                    world[y][x].neighbours++;
                }
            }

            // right-top neighbour
            if (x < world[y].size() - 1 && y > 0)
            {
                if (world[y - 1][x + 1].isLive == true)
                {
                    world[y][x].neighbours++;
                }
            }

            // left-bottom neighbour
            if (x > 0 && y < world.size() - 1)
            {
                if (world[y + 1][x - 1].isLive == true)
                {
                    world[y][x].neighbours++;
                }
            }

            // right-bottom neighbour
            if (x < world[y].size() - 1 && y < world.size() - 1)
            {
                if (world[y + 1][x + 1].isLive == true)
                {
                    world[y][x].neighbours++;
                }
            }
        }
    }

    for (unsigned int y = 0; y < world.size(); ++y)
    {
        for (unsigned int x = 0; x < world[0].size(); ++x)
        {
            Cell* current = &world[y][x];
            if (current->isLive == false && current->neighbours == 3)
            {
                current->isLive = true;
            }
            else if (current->isLive == true && (current->neighbours == 3 || current->neighbours == 2))
            {
                current->isLive = true;
            }
            else
            {
                current->isLive = false;
            }

            if (current->isLive)
            {
                current->Color = glm::vec3(1.f, 1.f, 1.f);
            }
            else
            {
                current->Color = glm::vec3(0.f, 0.f, 0.f);
            }
        }
    }
}