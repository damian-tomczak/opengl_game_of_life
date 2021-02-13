#pragma once

#include <map>
#include <string>

#include <glad/glad.h>

#include "shader.h"

class ResourceManager
{
public:
	// resource storage
	static std::map<std::string, Shader> Shaders;

	static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);

	static Shader& GetShader(std::string name);

	static void Clear();

private:
	ResourceManager() {};
	static Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);


};