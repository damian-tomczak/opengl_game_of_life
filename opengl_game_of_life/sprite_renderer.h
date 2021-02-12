#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"


class SpriteRenderer
{
public:
	SpriteRenderer(Shader& shader);

	~SpriteRenderer();

	void DrawSprite(glm::vec2 position, glm::vec2 size = glm::vec2(10.f, 10.f), float roate = 0.0f, glm::vec3 color = glm::uvec3(1.f));
private:
	Shader shader;
	unsigned int quadVAO;
	void initRenderData();
};

