// Copyright [2024] <Gia Panchal>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PhotoMagic.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Incorrect command inputs" << std::endl;
        return 1;
    }
    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];
    std::string password = argv[3];
    sf::Image image;
    sf::Texture inputTexture;
    sf::Texture encryptTexture;
    sf::Texture decryptTexture;
    sf::Sprite orignalSprite;
    sf::Sprite encryptSprite;
    sf::Sprite decryptSprite;

    for (char& c : password) {
        if (isalnum(c) && c != 0 && c != 1) {
            password = PhotoMagic::convertToBinary(password);
        }
    }
    if (!image.loadFromFile(argv[1])) {
        std::cerr << "Couldn't load image" << std::endl;
        return 1;
    }

    PhotoMagic::FibLFSR encrypt_key(password);
    PhotoMagic::FibLFSR decrypt_key(password);

    inputTexture.loadFromImage(image);
    orignalSprite.setTexture(inputTexture);

    PhotoMagic::transform(image, &encrypt_key);

    if (!image.saveToFile(argv[2])) {
        std::cerr << "Couldn't save output image" << std::endl;
        return 1;
    }

    encryptTexture.loadFromImage(image);
    encryptSprite.setTexture(encryptTexture);

    PhotoMagic::transform(image, &decrypt_key);

    decryptTexture.loadFromImage(image);
    decryptSprite.setTexture(decryptTexture);

    sf::Vector2u size = image.getSize();
    sf::RenderWindow window1(sf::VideoMode(size.x * 2, size.y), "Orignal | Transformed");
    sf::RenderWindow window2(sf::VideoMode(size.x * 2, size.y), "Transformed | Orignal");

    while (window1.isOpen() && window2.isOpen()) {
        sf::Event event;
        while (window1.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window1.close();
        }
        while (window2.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window2.close();
        }

        window1.clear();
        orignalSprite.setPosition(0, 0);
        window1.draw(orignalSprite);
        encryptSprite.setPosition(size.x, 0);
        window1.draw(encryptSprite);
        window1.display();

        window2.clear();
        encryptSprite.setPosition(0, 0);
        window2.draw(encryptSprite);
        decryptSprite.setPosition(size.x, 0);
        window2.draw(decryptSprite);
        window2.display();
    }

    return 0;
}
