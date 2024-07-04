#include "Game.hpp"
#include <SFML/Graphics.hpp>




// Initialize static game variables
sf::Clock Game::clock;
float Game::timeDelta;
sf::RenderWindow Game::window(sf::VideoMode(WINDOW_W, WINDOW_H), "Tower Defense");


void Game::init() {
    Game::window.setFramerateLimit(FRAME_RATE);
    Game::timeDelta = Game::clock.restart().asSeconds();
}


void Game::resetTimeDelta() {
    Game::timeDelta = Game::clock.restart().asSeconds();
}
