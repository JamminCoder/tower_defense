#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Explosions.hpp"
#include "Audio.hpp"

class Bullet : public Entity {
public:
    float speed;
    Bullet(Vec2f pos, Vec2f vector, float speed);
    void update(int bulletIndex);
    bool hasHitWall();
    void explode();
};