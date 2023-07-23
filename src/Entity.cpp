#include "Entity.hpp"


Entity::Entity(Vec2f pos, Vec2f size, const char* texturePath)
    : pos(pos), 
    size(size)
{
    sprite.setPosition(pos);
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    rect.setSize(Vec2f(size.x, size.y));
    rect.setPosition(pos);
}


void Entity::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}