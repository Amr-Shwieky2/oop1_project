#include "Controller.h"

int main() {
	Controller controller;
	return EXIT_SUCCESS;
}

//
//#include <SFML/Graphics.hpp>
//#include <vector>
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Transition");
//
//    // Load textures
//    std::vector<sf::Texture> textures;
//    textures.emplace_back(sf::Texture());
//    textures[0].loadFromFile("story1.png");
//    textures.emplace_back(sf::Texture());
//    textures[1].loadFromFile("story2.png");
//    textures.emplace_back(sf::Texture());
//    textures[2].loadFromFile("story3.png");
//    textures.emplace_back(sf::Texture());
//    textures[3].loadFromFile("story4.png");
//
//    sf::Sprite sprite;
//    sprite.setTexture(textures[0]);
//    sprite.setPosition(100, 100);
//
//    int currentTextureIndex = 0;
//    bool isTransitioning = false;
//    float transitionDuration = 0.5f; // Transition duration in seconds
//    sf::Clock transitionClock;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            else if (event.type == sf::Event::MouseButtonPressed) {
//                if (event.mouseButton.button == sf::Mouse::Left) {
//                    // Start transition if not already transitioning
//                    if (!isTransitioning) {
//                        isTransitioning = true;
//                        currentTextureIndex = (currentTextureIndex + 1) % textures.size();
//                        transitionClock.restart();
//                    }
//                }
//            }
//        }
//
//        if (isTransitioning) {
//            // Calculate interpolation factor (0 to 1)
//            float interpolation = transitionClock.getElapsedTime().asSeconds() / transitionDuration;
//            if (interpolation >= 1.0f) {
//                // Transition completed
//                isTransitioning = false;
//                interpolation = 1.0f;
//            }
//
//            // Apply interpolation to sprite properties (e.g., opacity)
//            sprite.setTexture(textures[currentTextureIndex], true);
//            sprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(255 * interpolation))); // Fade in/out
//
//            // You can also apply other animations here, such as scaling, rotation, etc.
//
//            // Draw the sprite
//            window.clear();
//            window.draw(sprite);
//            window.display();
//        }
//    }
//
//    return 0;
//}
