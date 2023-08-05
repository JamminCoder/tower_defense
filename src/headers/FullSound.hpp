#include <SFML/Audio.hpp>


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