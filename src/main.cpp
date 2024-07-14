#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <stack>

#include "Tower.hpp"
#include "Turret.hpp"
#include "Bullets.hpp"
#include "Explosions.hpp"
#include "Game.hpp"

int main()
{

    Game::init();
    
    Turret turret(Game::WINDOW_W / 2, Game::WINDOW_H / 2 + Game::WINDOW_H / 4, 64);
    turret.showHitbox();

    /* Main Loop */
    while (Game::window.isOpen())
    {
        /* Events */
        sf::Event event;
        while (Game::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                Game::window.close();
                Bullets::clear();
            }
        }

        Game::resetTimeDelta();

        /* Display */
        turret.draw();
        Bullets::draw();
        Explosions::draw();

        /* Updates */
        Bullets::update();
        Explosions::update();

        Game::window.display();
        Game::window.clear();
    }
}