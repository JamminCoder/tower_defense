#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "Particle.hpp"
#include "Explosion.hpp"
#include "ExplosionManager.hpp"
#include "shorthand.hpp"
#include "TextureLoader.hpp"
#include "Game.hpp"


Explosion::Explosion(Vec2f pos, int particleCount, float particleSpeed, sf::Time lifetime) {
    this->pos = pos;
    this->particleCount = particleCount;
    this->particleSpeed = particleSpeed;
    this->lifetime = lifetime;

    this->startTime = sf::Clock();
    this->particleSprite.setOrigin(particleTexture.getSize().x / 2.0f, particleTexture.getSize().y / 2.0f);
    this->particleSprite.setTexture(TextureLoader::particleTexture);
}



void Explosion::draw() {
    if (this->isDone) return;
    
    // Generate new particles on mouse click (left mouse button)
    for (int i = 0; i < this->particleCount; ++i) {
        Particle randParticle = this->randomParticle();
        particles.push_back(randParticle);
    }
}

Particle Explosion::randomParticle() {
    Vec2f particlePos = this->pos;
    float particleAngle = (rand() % 360) * 3.14f / 180.0f;
    float particleSpeed = (rand() % 360) + this->particleSpeed;
    Vec2f particleVelocity = Vec2f(std::cos(particleAngle) * particleSpeed, std::sin(particleAngle) * particleSpeed);
    sf::Time particleLifetime = sf::milliseconds(rand() % this->lifetime.asMilliseconds() + 200);

    Particle particle(particlePos, particleVelocity, particleLifetime);
    return particle;
}

void Explosion::update(int explosionIndex) {

    for (size_t i = 0; i < particles.size(); ++i) {
        Particle& particle = particles[i];
        particle.pos.x += particle.velocity.x * Game::timeDelta;
        particle.pos.y += particle.velocity.y * Game::timeDelta;
        
        float alpha = particle.lifetime.asMilliseconds() / 10 / (float)this->startTime.getElapsedTime().asMilliseconds();

        particleSprite.setPosition(particle.pos);
        particleSprite.setColor(sf::Color(255, 255, 255, alpha * 255));
        Game::window.draw(particleSprite);

        particle.lifetime -= this->lifeDecrease;

        if (particle.lifetime <= sf::Time::Zero) {
            particles.erase(particles.begin() + i);
            --i;
        }
    }
    

    sf::Time elapsed = this->startTime.getElapsedTime();
    if (elapsed >= this->lifetime) {
        this->isDone = true;
        ExplosionManager::explosions.erase(ExplosionManager::explosions.begin() + explosionIndex);
    }

}
