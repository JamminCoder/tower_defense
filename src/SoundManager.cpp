#include <SFML/Audio.hpp>
#include "SoundManager.hpp"

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
