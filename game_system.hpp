#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "ship.hpp"


struct GameSystem
{
    static std::vector<std::shared_ptr<Ship>> ships;
    static sf::Texture spritesheet;
    static sf::Sprite invader;
    static sf::Sprite player;
    static sf::Keyboard::Key controls[5];

    static void init();
    static void clean();
    static void update(const float& dt);
    static void render(sf::RenderWindow& window);
};