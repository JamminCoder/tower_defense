#pragma once
#include "shorthand.hpp"
#include "Entity.hpp"
#include <SFML/Graphics.hpp>


class Turret : public Entity {
public:
    float angle;
    int length;

    Turret(int x, int y, int length);
    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
};