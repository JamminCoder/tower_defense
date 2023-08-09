#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Explosion.hpp"
#include "shorthand.hpp"
#include "TextureLoader.hpp"


Explosion::Explosion(Vec2f pos, int lifetime_ms) {
    this->pos = pos;
    lifetime = sf::milliseconds(lifetime_ms);
    lifeDecrease = sf::milliseconds(1000 / 30); // Assuming 30 FPS
    particleSprite.setOrigin(particleTexture.getSize().x / 2.0f, particleTexture.getSize().y / 2.0f);
}


void Explosion::draw(sf::RenderWindow& window) {
    if (this->isDone) return;
    particleSprite.setTexture(TextureLoader::particleTexture);
    
    // Generate new particles on mouse click (left mouse button)
    for (int i = 0; i < NUM_PARTICLES; ++i) {
        Particle particle;
        particle.position = this->pos;
        float angle = static_cast<float>(rand() % 360) * 3.14f / 180.0f;
        float speed = static_cast<float>(rand() % 360) + PARTICLE_SPEED;
        particle.velocity = Vec2f(std::cos(angle) * speed, std::sin(angle) * speed);
        particle.lifetime = sf::milliseconds(rand() % PARTICLE_LIFETIME_MS + 200);
        particles.push_back(particle);
    }
}

void Explosion::update(sf::RenderWindow& window) {
    for (size_t i = 0; i < particles.size(); ++i) {
        Particle& particle = particles[i];
        particle.position.x += particle.velocity.x * sf::seconds(1.0f / 60.0f).asSeconds();
        particle.position.y += particle.velocity.y * sf::seconds(1.0f / 60.0f).asSeconds();
        
        float alpha = particle.lifetime.asSeconds() / (PARTICLE_LIFETIME_MS / 1000.0f);
        alpha /= alpha / lifetime.asSeconds();
        particleSprite.setPosition(particle.position);
        particleSprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
        window.draw(particleSprite);

        particle.lifetime -= this->lifeDecrease;

        if (particle.lifetime <= sf::Time::Zero) {
            particles.erase(particles.begin() + i);
            --i;
        }
    }
    
    this->lifetime -= this->lifeDecrease;
    if (this->lifetime <= sf::Time::Zero) {
        this->isDone = true;
    }

}
