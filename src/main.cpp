#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <stack>

#include "Tower.hpp"
#include "Turret.hpp"
#include "FullSound.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Tower Defense");
    window.setFramerateLimit(30);

    Tower tower(100, 150, 64, 128);
    tower.showHitbox();

    Turret turret(100, 100, 100);
    turret.showHitbox();

    FullSound* sounds[8];
    int index = 0;

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
                sounds[index] = new FullSound("/home/tim/Music/sound_effects/gun_shots/garand.wav");
                std::cout << "Fire\n";
                sounds[index]->play();
                index++;
                if (index > 8) index = 0;
            }
        }

        /* Updates */
        

        /* Display */
        tower.draw(window);
        turret.draw(window);

        window.display();
        window.clear();
    }
}