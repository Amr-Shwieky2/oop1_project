
#include "Controller.h"

Controller::Controller() {
    levelsInGame("Levels.txt");
    m_window.create(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
    setSoundBuffers(); m_openingSound.play();
    m_screens.OpeningBackground(m_window);

    while (m_window.isOpen()) {
        m_window.clear();
        if (m_mainPage) {
            startTheGame();
        }
        if (auto event = sf::Event{}; m_window.pollEvent(event)) {

            handleEvents(event);
        }
        m_window.display();
    }
}

void Controller::startTheGame() {
    if (m_window.isOpen()) {
        m_screens.drawBackground(m_window);
        m_screens.drawStarterSection(m_window);
        m_screens.drawSoundButton(m_window, m_mute);
    }
}

void Controller::handleEvents(sf::Event event) {
    switch (event.type) {
    case sf::Event::Closed:
        // Close the window if 'X' button is clicked
        m_window.close();
        break;
    case sf::Event::MouseButtonReleased:
        std::cout << event.mouseButton.x << " " << event.mouseButton.y;
        buttonReleased(event);
        
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

void Controller::buttonReleased(sf::Event event) {
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    int i = checkButtons(y);

    if (i == 1 && x < 725 && x > 550) { // new game
        m_clickSound.play();
        m_mainPage = false;
        // board
    }
    else if (i == 2 && x < 690 && x > 590) {
        m_clickSound.play();
        m_mainPage = false; 
        // score table
    }
    else if (i == 3 && x < 670 && x > 605) { // exit button
        m_clickSound.play();
        m_mainPage = false;
        m_window.close();
    }
    else if (checkSoundIconPressed(x) == 20) { // volume button
        m_clickSound.play();
        std::cout << "Noor";
        m_mute = !m_mute;
        m_screens.drawSoundButton(m_window, m_mute);
        m_mute ? m_openingSound.stop() : m_openingSound.play();
    }
}

void Controller::setSoundBuffers() {
    m_openingSoundBuffer.loadFromFile("opening.wav");
    m_openingSound.setBuffer(m_openingSoundBuffer);

    m_clickSoundBuffer.loadFromFile("click.wav");
    m_clickSound.setBuffer(m_clickSoundBuffer);
}

int Controller::checkSoundIconPressed(int val) {
    if (val >= 15 && val <= 55) return 20;
    return 0;
}

int Controller::checkButtons(int val) {
    size_t j = 0;

    if (val >= 220 && val <= 260 ) {
        j = 1;
    }
    else if (val >= 340 && val <= 380) {
        j = 2;
    }
    else if (val >= 460 && val <= 500) {
        j = 3;
    }
    else ;

    return j;
}