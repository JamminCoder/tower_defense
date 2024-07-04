#include "Bullets.hpp"
#include "Explosion.hpp"
#include <iostream>
#include "Game.hpp"

std::vector<Bullet> Bullets::bullets; 

void Bullets::update() {
    for (int i = 0; i < Bullets::bullets.size(); i++) {
        Bullet& bullet = Bullets::bullets.at(i);
        Vec2f pos = bullet.sprite.getPosition();
        bool isCollision = !((pos.x <= WINDOW_W && pos.x > 0) && (pos.y <= WINDOW_H && pos.y > 0));
        bullet.update();

        if (isCollision) {
            bullet.explode();
            Bullets::bullets.erase(Bullets::bullets.begin() + i);
        }
        
    }
}

void Bullets::draw() {
    for (Bullet& bullet : Bullets::bullets) {
        bullet.draw();
    }
}

void Bullets::add(Bullet bullet) {
    Bullets::bullets.push_back(bullet);
}

void Bullets::clear() {
    Bullets::bullets.clear();
}
