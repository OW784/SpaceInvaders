#include "game_system.hpp"
#include <iostream>


sf::Texture GameSystem::spritesheet;
sf::Sprite GameSystem::invader;

void GameSystem::init()
{
    if (!spritesheet.loadFromFile("res/textures/invaders_sheet.png"))
    {
        std::cerr << "Failed to load spritesheet" << std::endl;
    }

    invader.setTexture(spritesheet);

    invader.setTextureRect(
        sf::IntRect(
            sf::Vector2i(0, 0),
            sf::Vector2i(32, 32)
        )
    );
}

void GameSystem::update(const float& dt)
{
}

void GameSystem::render(sf::RenderWindow& window)
{
    window.draw(invader);
}

void GameSystem::clean()
{
}