#include "Bullet.hpp"

Bullet::Bullet(int x, int y, Vec2f velocity) :
    Entity(x, y, 5, 5, ""),
    vel(velocity)
{
    this->showHitbox();
    this->hitbox.setFillColor(sf::Color::Red);
}


void Bullet::update() {
    pos.x += vel.x;
    pos.y += vel.y;
    this->sprite.setPosition(pos);
    this->hitbox.setPosition(pos);
}

void Bullet::draw(sf::RenderWindow& window) {
    if (this->isShowingHitbox) window.draw(this->hitbox);
    window.draw(this->hitbox);
}