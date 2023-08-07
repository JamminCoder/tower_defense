#pragma once
#include "ParticleExplosion.hpp"

class ExplosionManager {
public:
    static std::vector<ParticleExplosion> explosions;

    static void draw(sf::RenderWindow& window);
    static void add(ParticleExplosion explosion);
};