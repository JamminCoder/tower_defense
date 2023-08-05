#include <math.h>
#include <iostream>
#include "Turret.hpp"
#include "Entity.hpp"
#include "Bullet.hpp"
#include "Bullets.hpp"

Turret::Turret(int x, int y, int length) :
    Entity(x, y, 2, length, "resources/turret.png"),
    canonSound("resources/audio/canon.wav"),
    rifleSound("resources/audio/garand.wav")
{
    this->length = length;
    this->sprite.setOrigin(Vec2f(0, 0));
};

Vec2f Turret::getMuzzlePosition() {
    return Vec2f(
        this->pos.x + this->length * std::cos(this->angle), 
        this->pos.y + this->length * std::sin(this->angle)
    );
}

void Turret::update(sf::RenderWindow& window) {
    Vec2i mousePos = sf::Mouse::getPosition(window);

    // Optional: Convert mouse position to world coordinates if needed
    Vec2f worldMousePos = window.mapPixelToCoords(mousePos);

    // Calculate angle in radians between line and mouse position
    this->angle = std::atan2(worldMousePos.y - pos.y, worldMousePos.x - pos.x);
    this->muzzlePos = this->getMuzzlePosition();

    float angleDegrees = angle * 180.0f / 3.1459265f;
    this->sprite.setRotation(angleDegrees);
}

void Turret::draw(sf::RenderWindow& window) {
    this->update(window);
    window.draw(this->sprite);
}

void Turret::fire() {
    Vec2f muzzlePos = this->getMuzzlePosition();
    Bullet bullet(muzzlePos.x, muzzlePos.y, Vec2f(muzzlePos.x / 10, muzzlePos.y / 10));
    Bullets::add(bullet);
    canonSound.play();
    rifleSound.play();
}