#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "ExplosionManager.hpp"
#include "Audio.hpp"

class Bullet : public Entity {
private:
    Vec2f vel;

public:
    int speed;
    Bullet(int x, int y, Vec2f velocity);
    void update();
    void draw(sf::RenderWindow& window);
    void explode();
};