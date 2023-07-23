#pragma once

#include "shorthand.hpp"
#include <SFML/Graphics.hpp>


class Entity {
private:
    Vec2f pos;
    Vec2f size;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape rect;

public:

    Entity(Vec2f pos, Vec2f size, const char* texturePath);
    void draw(sf::RenderWindow& window);
};
