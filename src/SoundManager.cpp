#include <SFML/Audio.hpp>
#include <iostream>
#include "SoundManager.hpp"

FullSound::FullSound(const char* audioFilePath) {
    if (!buffer.loadFromFile(audioFilePath)) {
        std::cerr << "Error loading shot file\n";
    }

    sound.setVolume(100);
    sound.setBuffer(buffer);
}

FullSound::FullSound(){}

bool FullSound::isDone() {
    return this->sound.getStatus() == sf::Sound::Stopped;
}

void FullSound::play() {
    sound.play();
}

SoundManager::SoundManager(){}
SoundManager::SoundManager(const char* audioFilePath) {
    this->load(audioFilePath);
}

void SoundManager::load(const char* audioFilePath) {
    for (int i = 0; i < SOUND_LIMIT; i++) {
        sounds[i] = new FullSound(audioFilePath);
    }
}

void SoundManager::play() {
    sounds[soundIndex]->play();
    this->updateSoundIndex();
}

void SoundManager::updateSoundIndex() {
    soundIndex++;
    if (soundIndex >= SOUND_LIMIT) soundIndex = 0;
}
