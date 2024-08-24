#include "Game.hpp"
#include "Entity.hpp"
#include <iostream>

Entity::Entity(Vec2f pos, Vec2f vel, Vec2f size, std::string texturePath, std::string name)
    : pos(pos), 
    vel(vel),
    size(size)
{
    this->sprite.setPosition(pos);
    this->hitbox.setPosition(pos);
    this->hitbox.setSize(size);
    this->hitbox.setOutlineColor(sf::Color::Red);
    this->hitbox.setOutlineThickness(1.0f);

    if (!texturePath.empty()) {
        this->texture.loadFromFile(texturePath);
        this->sprite.setTexture(texture);
    }
    
    name.empty() ?  this->name = "Entity" : this->name = name;
}

void Entity::draw() {
    if (isShowingHitbox) Game::window.draw(hitbox);
    Game::window.draw(sprite);
}


void Entity::move() {
    this->sprite.move(this->vel * Game::timeDelta);
    this->hitbox.move(this->vel * Game::timeDelta);
    this->pos = this->getPos();
}

void Entity::update() {
    this->move();
    this->draw();
}


Vec2f Entity::getPos() {
    return this->hitbox.getPosition();;
}

void Entity::setPos(Vec2f pos) {
    this->pos = pos;
    this->sprite.setPosition(pos);
    this->hitbox.setPosition(pos);
}

void Entity::showHitbox() {
    isShowingHitbox = true;
}

void Entity::hideHitbox() {
    isShowingHitbox = false;
}