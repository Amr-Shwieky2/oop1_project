
#include "Controller.h"

Controller::Controller() {
    levelsInGame("Levels.txt");
    m_window.create(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
    if (m_window.isOpen()) {
        m_screens.OpeningBackground(m_window);
    }
    
    while (m_window.isOpen()) {
        m_window.clear();
        m_screens.drawBackground(m_window);
        m_screens.drawStarterSection(m_window);
        m_screens.drawMap(m_window);
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
    case sf::Event::KeyReleased:
        if (event.key.code == sf::Keyboard::Left) {
            // Handle left key release
        }
        else if (event.key.code == sf::Keyboard::Right) {
            // Handle right key release
        }
        else if (event.key.code == sf::Keyboard::Up) {
            // Handle up key release
        }
        else if (event.key.code == sf::Keyboard::Down) {
            // Handle down key release
        }
        break;
    }
}

int Controller::levelsInGame(std::string str) {
    std::ifstream file(str);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;
    int lineCount = 0;
    while (std::getline(file, line)) {
        ++lineCount;
    }

    file.close();
    return lineCount;
}

