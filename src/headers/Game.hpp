#pragma once
#include <SFML/Graphics.hpp>




class Game {
public:
    static sf::Clock clock;
    static float timeDelta;

    static void resetTimeDelta();
};