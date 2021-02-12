#include "cell.h"

Cell::Cell()
    : GameObject() { }

Cell::Cell(glm::vec2 pos, glm::vec2 size, bool isLive, int neighbours)
    : GameObject(pos, size, glm::vec3(0.f, 0.f, 0.f)), isLive(isLive), neighbours(neighbours)
{
    if (isLive)
        Color = glm::vec3(1.f, 1.f, 1.f);
    else
        Color = glm::vec3(0.f, 0.f, 0.f);
}