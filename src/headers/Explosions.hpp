#pragma once
#include "Explosion.hpp"

class Explosions {
private:
    static void draw();
    
public:
    static std::vector<Explosion> explosions;

    static void update();
    static void add(Explosion explosion);
};