#include <iostream>
#include "Bullet.hpp"
#include "Explosion.hpp"
#include "ExplosionManager.hpp"
#include "TextureLoader.hpp"
#include "AudioLoader.hpp"
#include "Game.hpp"

Bullet::Bullet(Vec2f pos, Vec2f vector, float speed) :
    Entity(pos.x, pos.y, 5, 5, "")
{
    this->speed = speed;
    this->vel = Vec2f(vector.x * speed, vector.y * speed);
    this->sprite.setTexture(TextureLoader::particleTexture);
    this->showHitbox();
}

void Bullet::update() {
    this->sprite.move(this->vel * Game::timeDelta);
    this->hitbox.move(this->vel * Game::timeDelta);
    this->pos = this->hitbox.getPosition();
}

void Bullet::explode() {
    Explosion explosion(this->pos, 100, 500.f, sf::milliseconds(200));
    ExplosionManager::add(explosion);
    AudioLoader::explosion.play();
}

void Bullet::draw(sf::RenderWindow& window) {
    if (this->isShowingHitbox) window.draw(this->hitbox);
    window.draw(this->sprite);
}