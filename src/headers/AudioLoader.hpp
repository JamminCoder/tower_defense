#include "Audio.hpp"
#include <SFML/Audio.hpp>


class AudioLoader {
public:
    static ConcurrentAudio explosion;
    static ConcurrentAudio turretFire;

    static void load();
};