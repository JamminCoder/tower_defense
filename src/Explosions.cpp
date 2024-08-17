#include "Explosions.hpp"
#include "Explosion.hpp"
#include <iostream>


std::vector<Explosion> Explosions::explosions;

void Explosions::add(Explosion explosion) {
    Explosions::explosions.push_back(explosion);
}

void Explosions::draw() {
    for (Explosion& explosion : Explosions::explosions) explosion.draw();
}

void Explosions::update() {
    Explosions::draw();
    for (int i = 0; i < Explosions::explosions.size(); i++) {
        Explosion& explosion = Explosions::explosions.at(i);
        explosion.update(i);
    }
}