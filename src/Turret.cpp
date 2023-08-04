#include "Turret.hpp"
#include <math.h>

Turret::Turret(int x, int y, int length) :
    turret(sf::Lines, 2),
    turretStart(x, y)
{
}

void Turret::draw(sf::RenderWindow& window) {
    mousePos = sf::Mouse::getPosition(window);
    // Optional: Convert mouse position to world coordinates if needed
    worldMousePos = window.mapPixelToCoords(mousePos);

    // Calculate angle in radians between line and mouse position
    angle = std::atan2(worldMousePos.y - turretStart.y, worldMousePos.x - turretStart.x);
    
    turret[0].position = turretStart;
    turret[1].position = turretStart + sf::Vector2f(100 * std::cos(angle), 100 * std::sin(angle));
    turret[0].color = sf::Color::Red;
    turret[1].color = sf::Color::Red;

    window.draw(this->turret);
}