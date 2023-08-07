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

class ParticleExplosion {
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
    ParticleExplosion(Vec2f pos);
    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
};