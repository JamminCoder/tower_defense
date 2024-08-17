#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <stack>

#include "Tower.hpp"
#include "Turret.hpp"
#include "Bullets.hpp"
#include "Explosions.hpp"
#include "Enemy.hpp"

#include "Game.hpp"



int main()
{

    Game::init();
    
    Turret turret(Game::WINDOW_W / 2, Game::WINDOW_H / 2 + Game::WINDOW_H / 4, 64);
    turret.showHitbox();
    Enemy enemy(Vec2f(200, 200));
    
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

        /* Updates and display */

        Game::update();

        enemy.update();
        turret.update();
        Bullets::update();
        Explosions::update();
    }
}