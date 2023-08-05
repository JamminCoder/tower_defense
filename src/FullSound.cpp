#include "FullSound.hpp"
#include <iostream>

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