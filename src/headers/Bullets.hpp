#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.hpp"

class Bullets {
public:
    static std::vector<Bullet> bullets;
    static void update(sf::RenderWindow& window, SoundManager explosionSound);
    static void draw(sf::RenderWindow& window);
    static void add(Bullet bullet);
    static void clear();
};