#include <SFML/Audio.hpp>
#include <iostream>
#include "Audio.hpp"

Audio::Audio(const char* audioFilePath) {
    if (!buffer.loadFromFile(audioFilePath)) {
        std::cerr << "Error loading shot file\n";
    }

    sound.setVolume(100);
    sound.setBuffer(buffer);
}

Audio::Audio(){}

bool Audio::isDone() {
    return this->sound.getStatus() == sf::Sound::Stopped;
}

void Audio::play() {
    this->sound.play();
}

ConcurrentAudio::ConcurrentAudio(){}
ConcurrentAudio::ConcurrentAudio(const char* audioFilePath) {
    this->load(audioFilePath);
}

void ConcurrentAudio::load(const char* audioFilePath) {
    for (int i = 0; i < SOUND_LIMIT; i++) {
        this->sounds[i] = new Audio(audioFilePath);
    }
}

void ConcurrentAudio::play() {
    this->sounds[soundIndex]->play();
    this->updateSoundIndex();
}

void ConcurrentAudio::updateSoundIndex() {
    this->soundIndex++;
    if (this->soundIndex >= SOUND_LIMIT) this->soundIndex = 0;
}
