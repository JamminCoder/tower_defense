#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <stack>

#include "Tower.hpp"
#include "Turret.hpp"
#include "SoundManager.hpp"
#include "Bullets.hpp"

#define WIDTH 1200
#define HEIGHT 800

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Tower Defense");
    window.setFramerateLimit(30);

    Turret turret(WIDTH / 2, HEIGHT / 2 + HEIGHT / 4, 64);
    turret.showHitbox();

    /* Main Loop */
    while (window.isOpen())
    {
        /* Events */
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                Bullets::clear();
            }
        }


        /* Display */
        turret.draw(window);
        Bullets::draw(window);

        window.display();

        /* Updates */
        Bullets::update();

        window.clear();
    }
}