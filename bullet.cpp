#include "bullet.hpp"
#include "ship.hpp"
#include "game_system.hpp"
#include "game_parameters.hpp"
#include <iostream>

using namespace sf;

using param = parameters;

unsigned char Bullet::_bulletPointer = 0;
Bullet Bullet::_bullets[256];
float param::bullet_speed = 200.0f;

Bullet::Bullet()
    : _mode(false)
{
}


void Bullet::update(const float& dt) {
    for (Bullet & b : _bullets)
    {
        b._update(dt);
    }
}


void Bullet::_update(const float& dt) {
    if (getPosition().y < -param::sprite_size || getPosition().y > param::game_height + param::sprite_size) {
        return;
    }
    else {
        move(sf::Vector2f(0, dt * param::bullet_speed * (_mode ? -1.0f : 1.0f)));
        const sf::FloatRect boundingBox = getGlobalBounds();
        std::shared_ptr<Ship>& player = GameSystem::ships[0]; //we know that the first ship is the player
        for (std::shared_ptr<Ship>& s : GameSystem::ships) {
            if (_mode && s == player) {
                //player bullets don't collide with player
                continue;
            }
            if (!_mode && s != player) {
                //invader bullets don't collide with other invaders
                continue;
            }
            if (!s->is_exploded() &&
                s->getGlobalBounds().intersects(boundingBox))
            {
                s->explode();

                setPosition(sf::Vector2f(-100, -100));
                return;
            }
        }
    }
}

void Bullet::render(sf::RenderWindow& window)
{
    for (const Bullet& b : _bullets)
    {
        window.draw(b);
    }
}

void Bullet::fire(const sf::Vector2f& pos, const bool mode) {
    std::cout << "FIRE! x=" << pos.x
        << " y=" << pos.y << std::endl;

    Bullet& bullet = _bullets[++_bulletPointer];
    if (mode)
        bullet.setTextureRect(IntRect(Vector2i(64,32), Vector2i(32,32)));
    else
        bullet.setTextureRect(IntRect(Vector2i(96,32), Vector2i(32,32)));
    bullet.setPosition(pos);
    bullet._mode = mode;
}

void Bullet::init() {
    for (int i = 0; i < 256; i++) {
        _bullets[i].setTexture(GameSystem::spritesheet);
        _bullets[i].setOrigin(param::sprite_size / 2.f, param::sprite_size / 2.f);
        _bullets[i].setPosition(-100, -100);
    }
}