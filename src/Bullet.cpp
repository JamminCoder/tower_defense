#include "Bullet.hpp"

Bullet::Bullet(int x, int y, Vec2f velocity) :
    Entity(x, y, 5, 5, ""),
    vel(velocity)
{
    this->showHitbox();
    this->hitbox.setFillColor(sf::Color::Red);
}


void Bullet::update() {
    pos += vel;
    this->sprite.move(vel);
    this->hitbox.move(vel);
}

void Bullet::draw(sf::RenderWindow& window) {
    if (this->isShowingHitbox) window.draw(this->hitbox);
    window.draw(this->hitbox);
}