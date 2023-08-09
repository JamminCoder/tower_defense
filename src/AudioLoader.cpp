#include "AudioLoader.hpp"


ConcurrentAudio AudioLoader::explosion;
ConcurrentAudio AudioLoader::turretFire;

void AudioLoader::load() {
    explosion.load("resources/audio/shotgun.wav");
    turretFire.load("resources/audio/turret.wav");
}