#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Explosion.hpp"
#include "shorthand.hpp"
#include "globals.hpp"
#include "TextureLoader.hpp"


Explosion::Explosion(Vec2f pos, int particleNum, float particleSpeed, sf::Time lifetime) {
    this->pos = pos;
    this->lifetime = lifetime;
    this->lifeDecrease = sf::milliseconds(1000 / FRAME_RATE);
    this->particleSprite.setOrigin(particleTexture.getSize().x / 2.0f, particleTexture.getSize().y / 2.0f);
    this->particleSprite.setTexture(TextureLoader::particleTexture);
}


void Explosion::draw(sf::RenderWindow& window) {
    if (this->isDone) return;
    
    // Generate new particles on mouse click (left mouse button)
    for (int i = 0; i < this->particleNum; ++i) {
        Particle particle;
        particle.position = this->pos;
        float angle = static_cast<float>(rand() % 360) * 3.14f / 180.0f;
        float speed = static_cast<float>(rand() % 360) + this->particleSpeed;
        particle.velocity = Vec2f(std::cos(angle) * speed, std::sin(angle) * speed);
        particle.lifetime = sf::milliseconds(rand() % this->lifetime.asMilliseconds() + 200);
        particles.push_back(particle);
    }
}

void Explosion::update(sf::RenderWindow& window) {
    for (size_t i = 0; i < particles.size(); ++i) {
        Particle& particle = particles[i];
        particle.position.x += particle.velocity.x * sf::seconds(1.0f / 60.0f).asSeconds();
        particle.position.y += particle.velocity.y * sf::seconds(1.0f / 60.0f).asSeconds();
        
        float alpha = particle.lifetime.asSeconds() / (this->lifetime.asMilliseconds() / 1000.0f);
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
