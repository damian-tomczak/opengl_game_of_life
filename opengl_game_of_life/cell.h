#pragma once

#include "game_object.h"
class Cell :
    public GameObject
{
public:
    Cell();
    Cell(glm::vec2 pos, glm::vec2 size, bool isLive, int neigbours);

    bool isLive;
    int neighbours;
};

