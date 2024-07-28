#include "Enemy.hpp"
#include <iostream>




Enemy::Enemy(Vec2f pos) :
    Entity(pos.x, pos.y, 20, 20, "") {
    this->showHitbox();
}


void Enemy::update() {
    this->vel = Vec2f(rand() % 20, rand() % 20);
    // this->
    this->move();
    std::cout << this->getPos().x << std::endl;
}