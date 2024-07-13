#include "Bullets.hpp"
#include "Explosion.hpp"
#include <iostream>
#include "Game.hpp"

std::vector<Bullet> Bullets::bullets; 

void Bullets::update() {
    for (int i = 0; i < Bullets::bullets.size(); i++) {
        Bullet& bullet = Bullets::bullets.at(i);
        bullet.update(i);
    }
}

void Bullets::draw() {
    for (Bullet& bullet : Bullets::bullets) bullet.draw();
}

void Bullets::add(Bullet bullet) {
    Bullets::bullets.push_back(bullet);
}

void Bullets::clear() {
    Bullets::bullets.clear();
}
