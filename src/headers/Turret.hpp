#pragma once
#include <SFML/Graphics.hpp>
#include "shorthand.hpp"
#include "Entity.hpp"
#include "Audio.hpp"

class Turret : public Entity {
private:
    sf::Time cooldown = sf::milliseconds(0);
    
public:
    float angle;
    float angleRads;
    int length;
    Vec2f muzzlePos;


    Turret(int x, int y, int length);
    void update(sf::RenderWindow& window, float timeDelta);
    void draw(sf::RenderWindow& window, float timeDelta);

    Vec2f getMuzzlePosition();
    Vec2f getFiringVector();
    void fire();
    void resetCooldown();
};