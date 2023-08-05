#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <stack>

#include "Tower.hpp"
#include "Turret.hpp"
#include "SoundManager.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Tower Defense");
    window.setFramerateLimit(30);

    Turret turret(100, 400, 100);
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
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                turret.fire();
            }
        }

        /* Updates */
        

        /* Display */
        turret.draw(window);

        window.display();
        window.clear();
    }
}