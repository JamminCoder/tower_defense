#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "ExplosionManager.hpp"
#include "Audio.hpp"

class Bullet : public Entity {
private:
    Vec2f vel;

public:
    float speed;
    Bullet(Vec2f pos, Vec2f vector, float speed);
    void update();
    void draw(sf::RenderWindow& window);
    void explode();
};