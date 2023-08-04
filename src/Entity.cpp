#include "Entity.hpp"


Entity::Entity(int x, int y, int width, int height, const char* texturePath)
    : pos(Vec2f(x, y)), 
    size(Vec2f(width, height))
{
    sprite.setPosition(pos);
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);

    hitbox.setSize(size);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1.0f);
    hitbox.setPosition(pos);
}


void Entity::draw(sf::RenderWindow& window) {
    if (isShowingHitbox) window.draw(hitbox);
    window.draw(sprite);
}


void Entity::showHitbox() {
    isShowingHitbox = true;
}

void Entity::hideHitbox() {
    isShowingHitbox = false;
}