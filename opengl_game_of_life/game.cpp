#include "game.h"

SpriteRenderer* Renderer;

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_INACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete Renderer;
}

void Game::Init()
{
    // load shaders
    ResourceManager::LoadShader("shaders/sprite.vert", "shaders/sprite.frag", nullptr, "sprite");
    // configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width/2),
        static_cast<float>(this->Height/2), 0.0f, -1.0f, 1.0f);

    ResourceManager::GetShader("sprite").Use().SetMatrix4("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

    // load levels
    GameLevel one; one.Load(this->Width/2, this->Height/2);
    this->Level = one;
}

void Game::Update(float dt)
{
    this->Level.Refresh();
}

void Game::ProcessInput(float dt)
{
    if (this->Keys[GLFW_KEY_E])
        this->State = GAME_ACTIVE;
}

void Game::Render()
{
    if (this->State == GAME_ACTIVE)
    {
        this->Level.Draw(*Renderer);
    }
    
}

