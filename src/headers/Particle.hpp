#pragma once
#include <SFML/Graphics.hpp>
#include "shorthand.hpp"


class Particle {
public:
    sf::Time lifetime;
    Vec2f velocity;
    Vec2f pos;


    Particle(Vec2f pos, Vec2f velocity, sf::Time lifetime);
};




