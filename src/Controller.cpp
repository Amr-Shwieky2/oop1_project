#include "Controller.h"
#include <memory>


Controller::Controller() {
    int count_levels = levelsInGame("Levels.txt");
    m_window.create(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
    m_screens.OpeningBackground(m_window);
    for (size_t i = 0; i < count_levels; i++) {
        Board board(m_mouse, m_cats, i+1);
        sf::Vector2f boardSize = board.getBoardSize();
        while (m_window.isOpen()) {
            m_window.clear();
            startTheGame();
            openLevel(boardSize.x, boardSize.y, i + 1, board);
            openInformation();
            handleMainEvents();
            m_window.display(); 
        }

        while (m_levelWindow.isOpen())
        {
            m_levelWindow.clear(sf::Color(238, 232, 170));
            handleLevelEvents(board);
            board.drawBoard(m_levelWindow);
            m_mouse.draw(m_levelWindow, m_passedTime);
            m_levelWindow.display();
        }
    }
}

void Controller::handleMainEvents() {
    auto event = sf::Event{};
    while (m_window.pollEvent(event)) {
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

void Controller::handleLevelEvents(Board & board) {
    if (auto event = sf::Event{}; m_levelWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            m_levelWindow.close();
            m_window.create(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
            m_mainPage = true;
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::Left) {
                m_mouse.setDirection(event.key.code);
            }
            else if (event.key.code == sf::Keyboard::Right) {
                m_mouse.setDirection(event.key.code);
            }
            else if (event.key.code == sf::Keyboard::Up) {
                m_mouse.setDirection(event.key.code);
            }
            else if (event.key.code == sf::Keyboard::Down) {
                m_mouse.setDirection(event.key.code);
            }
            std::cout << "Level event\n";
            break;
        }
    }
    static sf::Clock clock;
    m_passedTime = clock.restart().asSeconds();
    moveDynamic(m_passedTime, board);
}

void Controller::startTheGame() {
    if (m_window.isOpen() && m_mainPage && !m_information) {
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

void Controller::checkCollision(Movable* character, Direction direction, Board & board)
{
    Icon* icon = board.getCharacters(character->getNextDirection(direction));
    if (icon != nullptr)
        icon->collide(character);
}

void Controller::moveDynamic(float passedTime, Board& board)
{
    //std::vector<std::vector<sf::Vector3i>> Tree;

    m_mouse.move(passedTime, board.getBoardSize());
    //checkCollision(&m_mouse, m_mouse.getDirection(), board);
    if (m_mouse.getMouseState()) {
        reternStartingPosition();
    }

    /*for (size_t i = 0; i < m_cats.size(); i++) {
        std::vector<std::vector<sf::Vector3i>> Tree = m_cats[i]->
            getBfsTree(sf::Vector2i((int)(m_mouse.getPosition().x / P_SIZE),
            (int)(m_mouse.getPosition().y / P_SIZE)), board.getMap(), board);

        m_cats[i]->move(passedTime, board.getBoardSize(), Tree);

    }*/
}

void Controller::reternStartingPosition()
{
    for (size_t i = 0; i < m_cats.size(); i++) {
        m_cats[i]->SetPosition(m_cats[i]->getStartPosition());
    }
    m_mouse.SetPosition(m_mouse.getStartPosition());
    m_mouse.setMouseState();
}

void Controller::draw(float passedTime, Board& board)
{
    /*if (m_mouse.getPosition().x != m_mouse.getPreviousPostion().x ||
        m_mouse.getPosition().y != m_mouse.getPreviousPostion().y) {*/
        
    /*}*/
    /*else if (first) {
        drawMovable(passedTime, board);
        first = false;
    }*/
}

void Controller::drawMovable(float passedTime, Board& board)
{

       // board.setMouse(m_mouse, m_mouse.getPosition());
       
}


//===============================================================================

void Controller::buttonReleased(sf::Event event) {
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    int i = checkButtons(y);

    if (i == 1 && x < 725 && x > 550) { // new game
        m_screens.playPauseSound(1, false); // play click
        m_mainPage = false;
        m_newGame = true;
    }
    else if (i == 2 && x < 740 && x > 540) {
        m_screens.playPauseSound(1, false); // play click
        m_information = true;
        //m_mainPage = false; 
        // score table
    }
    else if (i == 3 && x < 670 && x > 605) { // exit button
        m_screens.playPauseSound(1, false); // play click

        m_mainPage = false;
        m_window.close();
    }
    else if (i == 0 && checkSoundIconPressed(x) == 20) { // volume button
        m_screens.playPauseSound(1, false); // play click
        std::cout << "mute button\n";
        m_mute = !m_mute;
        m_screens.drawSoundButton(m_window, m_mute);
        m_screens.playPauseSound(0, m_mute);
        /*m_mute ? m_openingSound.stop() : m_openingSound.play();*/
    }
}


void Controller::openLevel(int rowSize, int colSize, unsigned int levelNumber, Board & board) {
    if (m_newGame) {
        m_window.close();
        m_levelWindow.create(sf::VideoMode(colSize, rowSize), "Level" + std::to_string(levelNumber));
        m_newGame = false;
        m_inGame = true;
    }
    //draw(m_passedTime, board);
    if (m_inGame) {
        drawMovable(m_passedTime, board);
        
        m_inGame = false;
    }
    
}

void Controller::openInformation() {
    if (m_information && m_mainPage) {
        m_screens.drawBackground(m_window);
    }
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

