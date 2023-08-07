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

const int NUM_PARTICLES = 200;
const int PARTICLE_LIFETIME_MS = 500;
const float PARTICLE_SPEED = 500.0f;

class Explosion {
private:
    // Create the particles vector
    std::vector<Particle> particles;
    sf::Texture particleTexture;
    sf::Sprite particleSprite;
    sf::Time lifeDecrease;
    sf::Time lifetime;
    Vec2f pos;

public:
    bool isDone = false;
    Explosion(Vec2f pos, int lifetime_ms);
    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
};