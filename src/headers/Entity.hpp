#pragma once

#include "shorthand.hpp"
#include <SFML/Graphics.hpp>


class Entity {
public:
    Vec2f pos;
    Vec2f size;
    bool isShowingHitbox = false;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape hitbox;

    Entity(int x, int y, int width, int height, const char* texturePath);
    void draw(sf::RenderWindow& window);
    void showHitbox();
    void hideHitbox();
    void setPos(Vec2f pos);
};
