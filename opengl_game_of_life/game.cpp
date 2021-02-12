#include "game.h"

SpriteRenderer* Renderer;

Game::Game(unsigned int width, unsigned int height)
    : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
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
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width/8),
        static_cast<float>(this->Height/8), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // set render-specific controls
    Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

    // load levels
    GameLevel one; one.Load(this->Width/8, this->Height/8);
    this->Level = one;
}

void Game::Update(float dt)
{
    this->Level.Refresh();
}

void Game::ProcessInput(float dt)
{
}

void Game::Render()
{
    if (this->State == GAME_ACTIVE)
    {
        this->Level.Draw(*Renderer);
    }
    
}

