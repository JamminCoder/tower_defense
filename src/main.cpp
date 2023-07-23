#include <SFML/Graphics.hpp>
#include "Entity.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Tower Defense");
    window.setFramerateLimit(30);

    Entity dude(Vec2f(100, 100), Vec2f(50, 50), "resources/Dude.png");

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
        dude.draw(window);


        window.display();
        window.clear();
    }
}