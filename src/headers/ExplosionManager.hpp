#pragma once
#include "Explosion.hpp"

class ExplosionManager {
public:
    static std::vector<Explosion> explosions;

    static void draw();
    static void add(Explosion explosion);
};