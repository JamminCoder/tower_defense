#include "TextureLoader.hpp"


sf::Texture TextureLoader::particleTexture;

void TextureLoader::loadTextures() {
    TextureLoader::particleTexture.loadFromFile("resources/particle.png");
}