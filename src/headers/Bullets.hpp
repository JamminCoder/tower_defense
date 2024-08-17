#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.hpp"
#include "Audio.hpp"

class Bullets {
public:
    static std::vector<Bullet> bullets;
    static void update();
    static void add(Bullet bullet);
    static void clear();
};