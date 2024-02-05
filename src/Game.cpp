#include "Game.hpp"
#include <SFML/Graphics.hpp>

#define WINDOW_W 1200
#define WINDOW_H 800
#define FRAME_RATE 30


// Initialize static game variables
sf::Clock Game::clock;
float Game::timeDelta;
sf::RenderWindow Game::window(sf::VideoMode(WINDOW_W, WINDOW_H), "Tower Defense");


void Game::init() {
    Game::window.setFramerateLimit(FRAME_RATE);
}


void Game::resetTimeDelta() {
    Game::timeDelta = Game::clock.restart().asSeconds();
}
