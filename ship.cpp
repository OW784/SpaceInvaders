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

void Ship::move_left()
{
	move(sf::Vector2f(-15.f, 0.f));
}

void Ship::move_right()
{
	move(sf::Vector2f(15.f, 0.f));
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
			if (dynamic_cast<Invader*>(ship.get())) {
				ship->move_down();
			}
		}
	}
		
}

Player::Player() :
	Ship(sf::IntRect(sf::Vector2i(param::sprite_size * 5, param::sprite_size),
		sf::Vector2i(param::sprite_size, param::sprite_size))) {
	setOrigin(param::sprite_size / 2.f, param::sprite_size / 2.f);;
	setPosition(param::game_width / 2.f, param::game_height - static_cast<float>(param::sprite_size));
}

void Player::Update(const float& dt) {
	Ship::Update(dt);

	sf::Vector2f position = getPosition();
	sf::FloatRect bounds = getGlobalBounds();

	if (sf::Keyboard::isKeyPressed(GameSystem::controls[0])) {
		move_left();

		bounds = getGlobalBounds();

		if (bounds.left < 0.f)
		{
			move(-bounds.left, 0.f);
		}
				
	}
	if (sf::Keyboard::isKeyPressed(GameSystem::controls[1])) {
		move_right();

		bounds = getGlobalBounds();

		if (bounds.left + bounds.width > param::game_width)
		{
			float overshoot =
				(bounds.left + bounds.width) - param::game_width;

			move(-overshoot, 0.f);
		}
	}
}