#include <iostream>
#include "Bullet.hpp"
#include "Explosion.hpp"
#include "ExplosionManager.hpp"
#include "TextureLoader.hpp"
#include "AudioLoader.hpp"

Bullet::Bullet(int x, int y, Vec2f velocity) :
    Entity(x, y, 5, 5, ""),
    vel(Vec2f(velocity.x * 20, velocity.y * 20))
{
    this->showHitbox();
    this->sprite.setTexture(TextureLoader::particleTexture);
}


void Bullet::update() {
    this->sprite.move(vel);
    this->hitbox.move(vel);
    this->pos = this->hitbox.getPosition();
}

void Bullet::explode() {
    Explosion explosion(this->hitbox.getPosition(), 500);
    ExplosionManager::add(explosion);
    AudioLoader::explosion.play();
}

void Bullet::draw(sf::RenderWindow& window) {
    if (this->isShowingHitbox) window.draw(this->hitbox);
    window.draw(this->sprite);
}