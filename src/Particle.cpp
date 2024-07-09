#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "shorthand.hpp"
#include "Game.hpp"
#include "Particle.hpp"


Particle::Particle(Vec2f pos, Vec2f velocity, sf::Time lifetime) {
    this->pos = pos;
    this->velocity = velocity;
    this->velocity = velocity;
    this->lifetime = lifetime;
}