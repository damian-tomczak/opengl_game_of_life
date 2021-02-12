#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "sprite_renderer.h"

class GameObject
{
public:
    glm::vec2   Position, Size;
    glm::vec3   Color;
    float       Rotation;

    GameObject();
    GameObject(glm::vec2 pos, glm::vec2 size);

    virtual void Draw(SpriteRenderer& renderer);
};