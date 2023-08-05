#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"


class Bullet : public Entity {
private:
    Vec2f vel;

public:
    Bullet(int x, int y, Vec2f velocity);
    void update();
    void draw(sf::RenderWindow& window);
};