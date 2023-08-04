#pragma once
#include "shorthand.hpp"
#include <SFML/Graphics.hpp>


class Turret {
private:
    Vec2i mousePos;
    Vec2f worldMousePos;

public:
    Vec2f turretStart;
    float angle;
    sf::VertexArray turret;

    int length;

    Turret(int x, int y, int length);
    void draw(sf::RenderWindow& window);

};