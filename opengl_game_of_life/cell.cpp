#include "cell.h"

Cell::Cell()
    : GameObject() { }

Cell::Cell(glm::vec2 pos, glm::vec2 size, bool isLive, int neigbours)
    : GameObject(pos, size) { }