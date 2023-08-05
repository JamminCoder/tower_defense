#pragma once
#include <SFML/Audio.hpp>
#include "FullSound.hpp"

#define SOUND_LIMIT 8


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