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

    SoundManager rifle;
    const char* rifleFile = "resources/audio/garand.wav";
    rifle.load(rifleFile);

    SoundManager canon;
    const char* canonFile = "resources/audio/canon.wav";
    canon.load(canonFile);
    
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
                rifle.play();
                canon.play();
            }
        }

        /* Updates */
        

        /* Display */
        turret.draw(window);

        window.display();
        window.clear();
    }
}