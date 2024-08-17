#include "Tower.hpp"

Tower::Tower(int x, int y, int width, int height) : 
    Entity(Vec2f(x, y), Vec2f(0, 0), Vec2f(width, height), "resources/tower.png")
{};

