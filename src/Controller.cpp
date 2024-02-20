#include "Controller.h"

Controller::Controller() {
    int count_levels = levelsInGame("Levels.txt");
    m_window.create(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
    setSoundBuffers(); m_openingSound.play();
    m_screens.OpeningBackground(m_window);
    for (size_t i = 0; i < count_levels; i++) {
        Board board(m_mouse, m_cats, i + 1);
        sf::Vector2f boardSize = board.getBoardSize();
        while (m_window.isOpen() || m_levelWindow.isOpen()) {
            m_mainPage ? m_window.clear() : m_levelWindow.clear();
            startTheGame();
            openLevel(boardSize.x, boardSize.y, i + 1, board);
            m_window.isOpen() ? handleMainEvents() : handleLevelEvents();
            m_mainPage ? m_window.display() : m_levelWindow.display();
        }
    }
}

void Controller::handleMainEvents() {
    if (auto event = sf::Event{}; m_window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            // Close the window if 'X' button is clicked
            m_window.close();
            break;
        case sf::Event::MouseButtonReleased:
            std::cout << event.mouseButton.x << " " << event.mouseButton.y;
            buttonReleased(event);
            break;
        }
    }
}

void Controller::handleLevelEvents() {
    if (auto event = sf::Event{}; m_levelWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            m_levelWindow.close();
            m_window.create(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
            m_mainPage = true;
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
            std::cout << "Amro ";
            break;
        }
    }
}

void Controller::startTheGame() {
    if (m_window.isOpen() && m_mainPage) {
        m_screens.drawBackground(m_window);
        m_screens.drawStarterSection(m_window);
        m_screens.drawSoundButton(m_window, m_mute);
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
        m_newGame = true;
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
    else if (i == 0 && checkSoundIconPressed(x) == 20) { // volume button
        m_clickSound.play();
        std::cout << "Noor";
        m_mute = !m_mute;
        m_screens.drawSoundButton(m_window, m_mute);
        m_mute ? m_openingSound.stop() : m_openingSound.play();
    }
}


void Controller::openLevel(int rowSize, int colSize, unsigned int levelNumber, Board& board) {
    if (m_newGame) {
        m_window.close();
        m_levelWindow.create(sf::VideoMode(rowSize, colSize), "Level" + std::to_string(levelNumber));
        //board.drawBoard(m_levelWindow);
        board.drawNonMovable(m_levelWindow);
        m_newGame = false;
    }
    // m_screens.drawBackground(m_window);
}

int Controller::checkSoundIconPressed(int val) {
    if (val >= 15 && val <= 55) return 20;
    return 0;
}

int Controller::checkButtons(int val) {
    int j = -1;

    if (val >= 20 && val <= 55) {
        j = 0;
    }
    else if (val >= 220 && val <= 260 ) {
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

void Controller::setSoundBuffers() {
    m_openingSoundBuffer.loadFromFile("opening.wav");
    m_openingSound.setBuffer(m_openingSoundBuffer);

    m_clickSoundBuffer.loadFromFile("click.wav");
    m_clickSound.setBuffer(m_clickSoundBuffer);   
    
    m_tomSoundBuffer.loadFromFile("tomRunning.wav");
    m_tomSound.setBuffer(m_tomSoundBuffer);
    
    m_jerrySoundBuffer.loadFromFile("click.wav");
    m_jerrySound.setBuffer(m_jerrySoundBuffer);

    m_catchSoundBuffer.loadFromFile("catch.wav");
    m_catchSound.setBuffer(m_catchSoundBuffer);
}