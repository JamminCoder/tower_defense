#include "Entity.hpp"
#include <iostream>

Entity::Entity(int x, int y, int width, int height, const char* texturePath)
    : pos(Vec2f(x, y)), 
    size(Vec2f(width, height))
{
    sprite.setPosition(pos);
    hitbox.setPosition(pos);
    hitbox.setSize(size);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.0f);

    if (texturePath[0] == '\0') return;
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
}


void Entity::draw(sf::RenderWindow& window) {
    if (isShowingHitbox) window.draw(hitbox);
    this->sprite.setTexture(texture);
    window.draw(sprite);
}


void Entity::setPos(Vec2f pos) {
    this->sprite.setPosition(pos);
    this->hitbox.setPosition(pos);
}

void Entity::showHitbox() {
    isShowingHitbox = true;
}

void Entity::hideHitbox() {
    isShowingHitbox = false;
}