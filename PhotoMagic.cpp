// Copyright [2024] <Gia Panchal>
#include "PhotoMagic.hpp"
std::string PhotoMagic::convertToBinary(std::string& Key) {
    int total = 0;
    for (unsigned int i = 0; i < Key.size(); i++) {
        total += static_cast<int>(Key[i]);
    }
    std::string binaryKey;
    while (total > 0) {
        int lastNum = total % 2;
        binaryKey = std::to_string(lastNum) + binaryKey;
        total /= 2;
    }
    return binaryKey;
}

void PhotoMagic::transform(sf::Image& image, FibLFSR* key) {
    unsigned int width = image.getSize().x;
    unsigned int height = image.getSize().y;

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            sf::Color pixel = image.getPixel(x, y);
            int red = pixel.r;
            int green = pixel.g;
            int blue = pixel.b;

            red ^= key->generate(8);
            green ^= key->generate(8);
            blue ^= key->generate(8);

            sf::Color newColor(red, green, blue);
            image.setPixel(x, y, newColor);
        }
    }
}
