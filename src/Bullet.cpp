#include <iostream>
#include "Bullet.hpp"
#include "Explosion.hpp"
#include "ExplosionManager.hpp"
#include "TextureLoader.hpp"
#include "AudioLoader.hpp"

Bullet::Bullet(Vec2f pos, Vec2f vector, float speed) :
    Entity(pos.x, pos.y, 5, 5, ""),
    vel(Vec2f(vector.x * speed, vector.y * speed))
{
    this->speed = speed;
    this->showHitbox();
    this->sprite.setTexture(TextureLoader::particleTexture);
}

void Bullet::setPos(Vec2f pos) {
    this->sprite.setPosition(pos);
    this->hitbox.setPosition(pos);
}

void Bullet::update(float timeDelta) {
    this->sprite.move(vel * timeDelta);
    this->hitbox.move(vel * timeDelta);
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