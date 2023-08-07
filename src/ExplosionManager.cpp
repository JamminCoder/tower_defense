#include "ExplosionManager.hpp"
#include "ParticleExplosion.hpp"
#include <iostream>


std::vector<ParticleExplosion> ExplosionManager::explosions;

void ExplosionManager::add(ParticleExplosion explosion) {
    ExplosionManager::explosions.push_back(explosion);
}

void ExplosionManager::draw(sf::RenderWindow& window) {
    for (int i = 0; i < ExplosionManager::explosions.size(); i++) {
        ParticleExplosion& explosion = ExplosionManager::explosions.at(i);
        explosion.draw(window);

        if (explosion.isDone) {
            ExplosionManager::explosions.erase(ExplosionManager::explosions.begin() + i);
        } else {
            explosion.update(window);
        }
    }
}