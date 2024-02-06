// Copyright [2024] <Gia Panchal>
#include <ctype.h>
#include "FibLFSR.hpp"
#include <SFML/Graphics.hpp>

namespace PhotoMagic {
// Transforms image using FibLFSR
void transform(sf::Image& image, FibLFSR* key);
// Display an encrypted copy of the picture, using the LFSR to do the encryption
std::string convertToBinary(std::string& Key);
}
