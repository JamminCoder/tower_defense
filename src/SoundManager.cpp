#include <SFML/Audio.hpp>
#include "SoundManager.hpp"


void SoundManager::play(const char* audioFilePath) {
    sounds[soundIndex] = new FullSound("/home/tim/Music/sound_effects/gun_shots/garand.wav");
    sounds[soundIndex]->play();
    this->updateSoundIndex();
}

void SoundManager::updateSoundIndex() {
    soundIndex++;
    if (soundIndex > SOUND_LIMIT) soundIndex = 0;
}
