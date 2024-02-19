
#include "Controller.h"

Controller::Controller() {
    sf::RenderWindow window(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
    while (window.isOpen()) {
        window.clear();
        m_screens.draw(window);
        window.display();

        if (auto event = sf::Event{}; window.waitEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                // Close the window if 'X' button is clicked
                window.close();
                break;
            }
        }
    }
}
