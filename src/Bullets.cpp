#include "Bullets.hpp"

std::vector<Bullet> Bullets::bullets; 

void Bullets::update() {
    for (Bullet& bullet : Bullets::bullets) {
        bullet.update();
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
