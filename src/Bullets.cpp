#include "Bullets.hpp"
#include "globals.hpp"
#include <iostream>

std::vector<Bullet> Bullets::bullets; 

void Bullets::update() {
    int i = 0;
    for (Bullet& bullet : Bullets::bullets) {
        Vec2f pos = bullet.sprite.getPosition();

        if (
            (pos.x <= WINDOW_W && pos.x > 0) &&
            (pos.y <= WINDOW_H && pos.y > 0)
        ) {
            bullet.update();
        } else {
            Bullets::bullets.erase(Bullets::bullets.begin() + i);
        }

        i++;
    }
}

void Bullets::draw(sf::RenderWindow& window) {
    for (Bullet& bullet : Bullets::bullets) {
        bullet.draw(window);
    }
}

void Bullets::add(Bullet bullet) {
    Bullets::bullets.push_back(bullet);
}

void Bullets::clear() {
    Bullets::bullets.clear();
}
