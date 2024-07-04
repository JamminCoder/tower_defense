#pragma once
#include <SFML/Graphics.hpp>


#define WINDOW_W 1200
#define WINDOW_H 800
#define FRAME_RATE 60

class Game {
public:
    static sf::Clock clock;
    static float timeDelta;
    static sf::RenderWindow window;

    static void resetTimeDelta();
    
    static void init();
};