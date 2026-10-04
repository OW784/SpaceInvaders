#pragma once

#include <SFML/Graphics.hpp>

struct GameSystem
{
    static sf::Texture spritesheet;
    static sf::Sprite invader;

    static void init();
    static void clean();
    static void update(const float& dt);
    static void render(sf::RenderWindow& window);
};