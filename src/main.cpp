#include <SFML/Graphics.hpp>
#include "Tower.hpp"
#include "Turret.hpp"
#include <math.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Tower Defense");
    window.setFramerateLimit(30);

    Tower tower(100, 150, 64, 128);
    tower.showHitbox();

    Turret turret(100, 100, 100);
    turret.showHitbox();

    /* Main Loop */
    while (window.isOpen())
    {

        /* Events */
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /* Updates */


        /* Display */
        tower.draw(window);
        turret.draw(window);

        window.display();
        window.clear();
    }
}