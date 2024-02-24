#pragma once

#include "Screens.h"
#include "PlayerStatus.h"
#include <thread>



class Controller
{
public:
	Controller();
	//~Controller();

private:
	void startTheGame();
	void handleMainEvents();
	void skipButton(sf::Event);
	void handleLevelEvents();

	bool levelEnded(const Board& board, unsigned int levelNum);

	void buttonReleased(sf::Event);

	int checkButtons(int x, int y);


	void openLevel(int, int, unsigned int, Board&);

	void gameStory();

	void openInformation();

	int checkSoundIconPressed(int val);


	int levelsInGame(std::string str);

	void checkCollision(Movable* character, Direction direction, Board& board);
	void moveDynamic(sf::RenderWindow& window, float passedTime, Board& board);

	void returnStartingPosition();

	bool m_mainPage = true;
	bool m_newGame = false;
	bool m_scoreTable = false;
	bool m_mute = false;
	bool m_information = false;
	
	bool m_storyShowed = false;

	sf::RenderWindow m_window;
	sf::RenderWindow m_levelWindow;

    Screens m_screens;

	Mouse m_mouse;
	std::vector<std::unique_ptr<Cat>> m_cats;

	PlayerStatus m_player;

	int m_countCheese;
};