#pragma once
#include <SFML/Graphics.hpp>
#include "shorthand.hpp"
#include "Entity.hpp"
#include "Audio.hpp"

class Turret : public Entity {
private:
    ConcurrentAudio rifleSound;
    ConcurrentAudio canonSound;
    sf::Time cooldown = sf::milliseconds(0);
    
public:
    float angle;
    float angleRads;
    int length;
    Vec2f muzzlePos;


    Turret(int x, int y, int length);
    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    Vec2f getMuzzlePosition();
    void fire();
};