#pragma once

#include "shorthand.hpp"
#include <SFML/Graphics.hpp>


class Entity {
public:
    Vec2f pos;
    Vec2f size;
    Vec2f vel;
    bool isShowingHitbox = false;
    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape hitbox;

    Entity(Vec2f pos, Vec2f vel, Vec2f size, std::string texturePath, std::string name);
    void draw();
    void move();
    virtual void update();
    
    void setPos(Vec2f pos);
    Vec2f getPos();

    void showHitbox();
    void hideHitbox();
};
