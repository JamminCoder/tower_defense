#include <SFML/Graphics.hpp>
#include "Tower.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Tower Defense");
    window.setFramerateLimit(30);

    Tower tower(100, 100, 64, 128);
    tower.showHitbox();

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


        window.display();
        window.clear();
    }
}