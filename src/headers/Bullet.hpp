#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "ExplosionManager.hpp"
#include "Audio.hpp"

class Bullet : public Entity {
public:
    float speed;
    Bullet(Vec2f pos, Vec2f vector, float speed);
    void update();
    void draw();
    void explode();
};