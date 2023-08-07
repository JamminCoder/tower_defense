#pragma once
#include <SFML/Audio.hpp>

#define SOUND_LIMIT 8

class FullSound {
private:
    sf::SoundBuffer buffer;
    sf::Sound sound;

public:
    FullSound(const char* audioFilePath);
    FullSound();

    bool isDone();
    void play();
};

class SoundManager {
private:
    int soundIndex = 0;
    FullSound* sounds[SOUND_LIMIT];
    void updateSoundIndex();

public:
    SoundManager(const char* audioFilePath);
    SoundManager();
    void play();
    void load(const char* audioFilePath);
};