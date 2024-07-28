#include "Game.hpp"
#include "Entity.hpp"
#include <iostream>

Entity::Entity(int x, int y, int width, int height, const char* texturePath)
    : pos(Vec2f(x, y)), 
    size(Vec2f(width, height)),
    vel(Vec2f(0, 0))
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


void Entity::draw() {
    if (isShowingHitbox) Game::window.draw(hitbox);
    // this->sprite.setTexture(texture);
    Game::window.draw(sprite);
}


Vec2f Entity::getPos() {
    return this->hitbox.getPosition();;
}

void Entity::setPos(Vec2f pos) {
    this->pos = pos;
    this->sprite.setPosition(pos);
    this->hitbox.setPosition(pos);
}


void Entity::move() {
    this->sprite.move(this->vel * Game::timeDelta);
    this->hitbox.move(this->vel * Game::timeDelta);
    this->pos = this->getPos();
}

void Entity::showHitbox() {
    isShowingHitbox = true;
}

void Entity::hideHitbox() {
    isShowingHitbox = false;
}