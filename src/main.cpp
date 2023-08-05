#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <stack>

#include "Tower.hpp"
#include "Turret.hpp"
#include "SoundManager.hpp"
#include "Bullet.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Tower Defense");
    window.setFramerateLimit(30);

    Turret turret(100, 400, 100);
    turret.showHitbox();

    Bullet bullet(100, 200, Vec2f(2.f, 1.f));

    /* Main Loop */
    while (window.isOpen())
    {

        /* Events */
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                turret.fire();
            }
        }


        /* Display */
        bullet.draw(window);
        turret.draw(window);

        window.display();

        /* Updates */
        bullet.update();

        window.clear();
    }
}