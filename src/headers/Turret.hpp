#pragma once
#include <SFML/Graphics.hpp>
#include "shorthand.hpp"
#include "Entity.hpp"
#include "SoundManager.hpp"

class Turret : public Entity {
private:
    SoundManager rifleSound;
    SoundManager canonSound;
    
public:
    float angle;
    int length;
    Vec2f muzzlePos;


    Turret(int x, int y, int length);
    void update(sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

    Vec2f getMuzzlePosition();
    void fire();
};