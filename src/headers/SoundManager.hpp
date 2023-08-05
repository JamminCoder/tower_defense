#include <SFML/Audio.hpp>
#include "FullSound.hpp"

#define SOUND_LIMIT 8


class SoundManager {
private:
    int soundIndex = 0;
    FullSound* sounds[SOUND_LIMIT];
    void updateSoundIndex();

public:
    void play();
    void load(const char* audioFilePath);
};