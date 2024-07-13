#include <iostream>
#include "Bullet.hpp"
#include "Explosion.hpp"
#include "ExplosionManager.hpp"
#include "TextureLoader.hpp"
#include "AudioLoader.hpp"
#include "Game.hpp"
#include "Bullets.hpp"

Bullet::Bullet(Vec2f pos, Vec2f vector, float speed) :
    Entity(pos.x, pos.y, 5, 5, "")
{
    this->speed = speed;
    this->vel = Vec2f(vector.x * speed, vector.y * speed);
    this->sprite.setTexture(TextureLoader::particleTexture);
    this->showHitbox();
}

void Bullet::update(int bulletIndex) {
    this->move();
    if (this->hasHitWall()) {
        this->explode();
        Bullets::bullets.erase(Bullets::bullets.begin() + bulletIndex);
    }
}

bool Bullet::hasHitWall() {
    bool isCollision = !(
        (this->pos.x <= Game::WINDOW_W && this->pos.x > 0) && 
        (this->pos.y <= Game::WINDOW_H && this->pos.y > 0));

    return isCollision;
}

void Bullet::explode() {
    int particleCount = 200;
    int particleSpeed = 200.f;
    Explosion explosion(this->pos, particleCount, particleSpeed, sf::milliseconds(250));
    ExplosionManager::add(explosion);
    AudioLoader::explosion.play();
}

void Bullet::draw() {
    if (this->isShowingHitbox) Game::window.draw(this->hitbox);
    Game::window.draw(this->sprite);
}