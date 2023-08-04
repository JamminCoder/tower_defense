#include "Turret.hpp"
#include "Entity.hpp"
#include <math.h>

Turret::Turret(int x, int y, int length) :
    Entity(x, y, 2, length, "resources/turret.png")
{
    this->length = length;
    this->sprite.setOrigin(Vec2f(0, 0));
};

void Turret::update(sf::RenderWindow& window) {
    Vec2i mousePos = sf::Mouse::getPosition(window);

    // Optional: Convert mouse position to world coordinates if needed
    Vec2f worldMousePos = window.mapPixelToCoords(mousePos);

    // Calculate angle in radians between line and mouse position
    angle = std::atan2(worldMousePos.y - pos.y, worldMousePos.x - pos.x);
    
    float angleDegrees = angle * 180.0f / 3.1459265f;
    this->sprite.setRotation(angleDegrees);
}

void Turret::draw(sf::RenderWindow& window) {
    this->update(window);
    window.draw(this->sprite);
}