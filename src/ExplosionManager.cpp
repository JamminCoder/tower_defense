#include "ExplosionManager.hpp"
#include "Explosion.hpp"
#include <iostream>


std::vector<Explosion> ExplosionManager::explosions;

void ExplosionManager::add(Explosion explosion) {
    ExplosionManager::explosions.push_back(explosion);
}

void ExplosionManager::draw() {
    for (int i = 0; i < ExplosionManager::explosions.size(); i++) {
        Explosion& explosion = ExplosionManager::explosions.at(i);
        explosion.draw();

        if (explosion.isDone) {
            ExplosionManager::explosions.erase(ExplosionManager::explosions.begin() + i);
        } else {
            explosion.update();
        }
    }
}