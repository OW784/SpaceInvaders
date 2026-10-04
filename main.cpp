#include <SFML/Graphics.hpp>
#include <iostream>



sf::Texture spritesheet;
sf::Sprite invader;

const int game_width = 800;
const int game_height = 600;


void init() {
    if (!spritesheet.loadFromFile("res/textures/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
    
}

void update(float dt) {
	
}

void render(sf::RenderWindow& window) {
    window.draw(invader);
	
}

void clean() {
	
}

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({ game_width, game_height }),
        "SpaceInvaders"
    );

    init();

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

        
        update(dt);

       
        window.clear();
        render(window);

        sf::sleep(sf::seconds(time_step));

        window.display();
    }

    clean();
}