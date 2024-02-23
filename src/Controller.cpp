#include "Controller.h"
#include <memory>

//m_window.create(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
   // m_screens.OpeningBackground(m_window);
    //m_window.isOpen() ||
        //m_mainPage ? m_window.clear() :
        //startTheGame();
    //openInformation();
    //m_window.isOpen() ? handleMainEvents() :
    //m_mainPage ? m_window.display() :

Controller::Controller() {
    int count_levels = levelsInGame("Levels.txt");

    for (size_t i = 0; i < count_levels; i++) {
        Board board(m_mouse, m_cats, int(i + 1));
        sf::Vector2f boardSize = board.getBoardSize();

        m_levelWindow.create(sf::VideoMode(static_cast<unsigned int>(boardSize.y), static_cast<unsigned int>(boardSize.x + 50)), "Level" + std::to_string(int(i + 1)));
        static sf::Clock clock;
        while (m_levelWindow.isOpen() && !isMouseDied() && !finshCheese()) {
            m_levelWindow.clear(sf::Color(238, 232, 170));
            

            static sf::Clock timer;
            timer.restart();
            static sf::Time allottedTime = board.getTime();
            m_gameTime = allottedTime.asSeconds() - timer.getElapsedTime().asSeconds();

            if (m_gameTime == 0)
                break;

            handleLevelEvents(clock);

            float passedTime = clock.restart().asSeconds();
            moveDynamic(passedTime, board);
            draw(passedTime, board);
            m_levelWindow.display();

        }

        // +score 
        m_cats.clear();
    }
}



void Controller::handleMainEvents() {
    if (m_mainPage && !m_information) {
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
    else {
        if (auto event = sf::Event{}; m_window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
                // Close the window if 'X' button is clicked
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
                std::cout << event.mouseButton.x << " " << event.mouseButton.y;
                skipButton(event);
                break;
            }
        }
    }
}

void Controller::skipButton(sf::Event event) {
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;

    if (x >= 1180 && x <= 1220) {
        if (y >= 30 && y <= 60) {
            startTheGame();
            m_information = false;
            m_mainPage = true;
        }
    }
}

void Controller::handleLevelEvents(sf::Clock& clock) {
    if (auto event = sf::Event{}; m_levelWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            m_levelWindow.close();
           // m_window.create(sf::VideoMode(40 * P_SIZE, 22 * P_SIZE), "Tom&Jerry - Catch me if you CAN!");
            m_mainPage = true;
            break;
        case sf::Event::KeyReleased:
            if ((event.key.code == sf::Keyboard::Left) || (event.key.code == sf::Keyboard::Right) ||
                (event.key.code == sf::Keyboard::Up) || (event.key.code == sf::Keyboard::Down)) {
                m_mouse.setDirection(event.key.code);
                clock.restart();
            }
            break;
        }
    }
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

void Controller::checkCollision(Movable* character, Direction direction, Board& board)
{
    Icon* icon = board.getCharacters(character->getNextDirection(direction));
    if (icon != nullptr)
        icon->collide(character);
}

void Controller::moveDynamic(float passedTime, Board& board)
{
    std::vector<std::vector<sf::Vector3i>> Tree = board.getBfsTree(sf::Vector2i((int)(m_mouse.getPosition().x / P_SIZE),
                                                                                (int)(m_mouse.getPosition().y / P_SIZE)));

    m_mouse.move(passedTime, board.getBoardSize());
    checkCollision(&m_mouse, m_mouse.getDirection(), board);


    if (m_mouse.getMouseState()) {
        reternStartingPosition();
    }

    for (size_t i = 0; i < m_cats.size(); i++) {
        m_cats[i]->move(passedTime, board.getBoardSize(), Tree);
        checkCollision(m_cats[i].get(), m_cats[i].get()->getDirection(), board);
        if (catchMouse(m_cats[i].get()))
            m_mouse.collide(m_cats[i].get());
    }
}

bool Controller::catchMouse(Cat* cat)
{
    return (abs(m_mouse.getPosition().x - cat->getPosition().x) < P_SIZE &&
        abs(m_mouse.getPosition().y - cat->getPosition().y) < P_SIZE);
}

void Controller::reternStartingPosition()
{
    for (size_t i = 0; i < m_cats.size(); i++)
        m_cats[i]->SetPosition(m_cats[i]->getStartPosition());

    m_mouse.SetPosition(m_mouse.getStartPosition());
    m_mouse.setMouseState();
}

bool Controller::isMouseDied()
{
    return m_mouse.getLife() <= 0 ? true : false;
}

bool Controller::finshCheese()
{
    return false;
}

void Controller::draw(float passedTime, Board& board)
{
    board.drawBoard(m_levelWindow);

    m_player.draw(m_levelWindow, m_mouse.getLife(), m_mouse.getScore(), board.getnumberOfLevel(),
                    m_gameTime, board.getBoardSize(), m_screens.getFont());

    movableDraw(passedTime);

}

void Controller::movableDraw(float passedTime)
{
    m_mouse.draw(m_levelWindow, passedTime);
    for (size_t i = 0; i < m_cats.size(); i++)
    {
        m_cats[i]->draw(m_levelWindow, passedTime);
    }
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
    }
}

void Controller::openLevel(int rowSize, int colSize, unsigned int levelNumber, Board& board) {
    if (m_newGame) {
        m_window.close();
        


        m_newGame = false;
    }
    board.drawBoard(m_levelWindow);
    m_player.draw(m_levelWindow, 3, 0, levelNumber, 5 ,board.getBoardSize(), m_screens.getFont());
}

void Controller::openInformation() {
    if (m_information && m_mainPage) {
        m_screens.drawBackground(m_window);
        m_screens.drawInformation(m_window);
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

