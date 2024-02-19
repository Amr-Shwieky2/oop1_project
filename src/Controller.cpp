
#include "Controller.h"

Controller::Controller() {
    m_window.create(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
    while (m_window.isOpen()) {
        m_window.clear();
        m_screens.drawBackground(m_window);
        m_window.display();

        if (auto event = sf::Event{}; m_window.pollEvent(event)) {
            handleEvents(event);
        }
    }
}

void Controller::handleEvents(sf::Event event) {
    switch (event.type) {
    case sf::Event::Closed:
        // Close the window if 'X' button is clicked
        m_window.close();
        break;
    }
}
