#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
public:
    Ship();
    Ship(const Ship& s);
    Ship(sf::IntRect ir);
    virtual ~Ship() = 0;

    void move_down();
    void move_left();
    void move_right();

    virtual void Update(const float& dt);

    bool is_exploded() const;
    virtual void explode();

protected:
    sf::IntRect _sprite;
    bool _is_exploded = false;
};

class Invader : public Ship {
public:
	static bool direction;
	static float speed;
	static float acc;
	Invader();
	Invader(const Invader& inv);
	Invader(sf::IntRect ir, sf::Vector2f pos);
	void Update(const float& dt) override;
};

class Player : public Ship {
public:
	Player();
	void Update(const float& dt) override;
};
