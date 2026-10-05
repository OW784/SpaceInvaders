#include "ship.hpp"
#include "game_system.hpp"
#include "game_parameters.hpp"

using param = parameters; //renaming the struct Parameters into param to have a more compact and readable code
using gs = GameSystem;

bool Invader::direction;
float Invader::speed;
float Invader::acc = 5.f;

Ship::Ship() {};

Ship::Ship(const Ship &s) :
	_sprite(s._sprite){}

Ship::Ship(sf::IntRect ir) : Sprite() {
	_sprite = ir;
	setTexture(GameSystem::spritesheet);
	setTextureRect(_sprite);
}

void Ship::Update(const float &dt){}

Ship::~Ship() = default;

Invader::Invader(const Invader& inv)
	: Ship(inv)
{
}

void Ship::move_down()
{
	move(sf::Vector2f(0.f, 10.f));
}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos)
	: Ship(ir)
{
	setOrigin(sf::Vector2f(16.f, 16.f));
	setPosition(pos);
}

void Invader::Update(const float& dt) {
	Ship::Update(dt);
		
	move(dt * (direction ? 1.0f : -1.0f) * speed, 0.0f);
	
	if ((direction && getPosition().x > param::game_width - param::sprite_size / 2.f) ||
		(!direction && getPosition().x < param::sprite_size / 2.f)) {
		direction = !direction;
		speed += Invader::acc;
		for (std::shared_ptr<Ship>& ship : gs::ships) {
			ship->move_down();
		}
	}
		
}