#include <SFML/Graphics.hpp>
#include "game_system.hpp"
#include "game_parameters.hpp"
#include <iostream>


int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ parameters::game_width, parameters::game_height}),
        "SpaceInvaders"
    );

    GameSystem::init();

    const float time_step = 1.0f / 60.0f;

    sf::Clock clock;

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        
        const float dt = clock.restart().asSeconds();

        
        GameSystem::update(dt);

       
        window.clear();
        GameSystem::render(window);

        sf::sleep(sf::seconds(time_step));

        window.display();
    }

    GameSystem::clean();
}