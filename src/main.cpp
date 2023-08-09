#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <stack>

#include "Tower.hpp"
#include "Turret.hpp"
#include "Bullets.hpp"
#include "globals.hpp"
#include "ExplosionManager.hpp"
#include "Audio.hpp"
#include "TextureLoader.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_W, WINDOW_H), "Tower Defense");
    window.setFramerateLimit(30);

    TextureLoader::loadTextures();

    Turret turret(WINDOW_W / 2, WINDOW_H / 2 + WINDOW_H / 4, 64);
    turret.showHitbox();
    ConcurrentAudio explosionSound("resources/audio/shotgun.wav");
    
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

        /* Updates */
        Bullets::update(window, explosionSound);
        ExplosionManager::draw(window);
        window.display();
        window.clear();
    }
}