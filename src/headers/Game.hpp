#pragma once
#include <SFML/Graphics.hpp>


class Game {
public:
    static const char* NAME;
    static int WINDOW_W;
    static int WINDOW_H;
    static int FRAME_RATE;

    static sf::Clock clock;
    static float timeDelta;
    static sf::RenderWindow window;

    static void resetTimeDelta();
    
    static void init();
};