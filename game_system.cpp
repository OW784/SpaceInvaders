#include "game_system.hpp"
#include "ship.hpp"
#include <iostream>
#include <memory>


sf::Texture GameSystem::spritesheet;
sf::Sprite GameSystem::invader;
std::vector<std::shared_ptr<Ship>> GameSystem::ships;

void GameSystem::init()
{
    if (!spritesheet.loadFromFile("res/textures/invaders_sheet.png"))
    {
        std::cerr << "Failed to load spritesheet" << std::endl;
    }

    invader.setTexture(spritesheet);

    Invader::speed = 20.f;
    Invader::direction = 5.f;

    for (int row = 0; row < 5; row++)
    {
        sf::IntRect sprite;

        if (row == 0) {
            sprite = sf::IntRect(
                sf::Vector2i(0, 0),
                sf::Vector2i(32, 32)
            );
        }
        else if (row == 1)
        {
            sprite = sf::IntRect(
                sf::Vector2i(32, 0),
                sf::Vector2i(32, 32)
            );
        }
        else if(row == 2)
        {
            sprite = sf::IntRect(
                sf::Vector2i(96, 0),
                sf::Vector2i(32, 32)
            );
        }
        else if (row == 3)
        {
            sprite = sf::IntRect(
                sf::Vector2i(128, 0),
                sf::Vector2i(32, 32)
            );
        }
        else if (row == 4)
        {
            sprite = sf::IntRect(
                sf::Vector2i(160, 0),
                sf::Vector2i(32, 32)
            );
        }


        for (int column = 0; column < 10; column++)
        {
            float x = 220.f + column * 40.f;
            float y = 100.f + row * 40.f;

            std::shared_ptr<Invader> inv =
                std::make_shared<Invader>(
                    sprite,
                    sf::Vector2f(x, y)
                );
            ships.push_back(inv);
        }
    }

}

void GameSystem::update(const float& dt)
{
    for (std::shared_ptr<Ship>& s : ships) {
        s->Update(dt);
    }
}

void GameSystem::render(sf::RenderWindow& window)
{
    for (const std::shared_ptr<Ship>& s : ships) {
        window.draw(*(s.get()));
    }
}

void GameSystem::clean() {
    for (std::shared_ptr<Ship>& ship : ships)
        ship.reset();
    ships.clear();
}