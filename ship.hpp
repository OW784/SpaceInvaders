#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
public:
	Ship();

	Ship(const Ship& s);

	Ship(sf::IntRect ir);

	virtual ~Ship() = 0;

	void move_down();
	
	virtual void Update(const float& dt);
protected:
	sf::IntRect _sprite;
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