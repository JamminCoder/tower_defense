#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include "shorthand.hpp"

struct Particle {
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Time lifetime;
};

// const int PARTICLE_LIFETIME_MS = 500;

class Explosion {
private:
    int particleCount;
    float particleSpeed;

    std::vector<Particle> particles;
    sf::Texture particleTexture;
    sf::Sprite particleSprite;
    sf::Time lifeDecrease;
    sf::Clock startTime;
    sf::Time lifetime;
    sf::Time maxLifetime;
    Vec2f pos;

public:
    bool isDone = false;
    Explosion(Vec2f pos, int particleNum, float particleSpeed, sf::Time lifetime);
    void draw();
    void update();
};