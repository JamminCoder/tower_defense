#include "Game.hpp"

sf::Clock Game::clock;
float Game::timeDelta;

void Game::resetTimeDelta() {
    Game::timeDelta = Game::clock.restart().asSeconds();
}
