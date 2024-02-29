#pragma once

#include "Screens.h"
#include "PlayerStatus.h"
#include <thread>

class Controller
{
public:
	Controller();
	~Controller();

private:
	void runGame();

	void startTheGame();
	void handleMainEvents();

	void handleLevelEvents();


	bool levelEnded(const Board& board, int levelNum);

	void buttonReleased(sf::Event);

	void openLevel();

	void gameStory();

	void openInformation();


	//======================================================================
	int levelsInGame(std::string str);
	void checkCollision(Movable* character, Direction direction, Board& board);

	void moveMovable(float passedTime, Board& board);
	bool catchMouse(Cat* cat);
	void returnStartingPosition();
	bool isMouseDied();

	//void draw(float passedTime, Board& board);
	void movableDraw(float passedTime);

	//======================================================================


	bool m_mainPage = true;
	bool m_newGame = false;
	bool m_scoreTable = false;
	bool m_mute = false;
	bool m_information = false;

	bool m_storyShowed = false;// to change when I want to push 
	bool m_nowMove = false;

	sf::RenderWindow m_window;
	sf::RenderWindow m_levelWindow;

	Screens m_screens;

	Mouse m_mouse;
	std::vector<std::unique_ptr<Cat>> m_cats;
	PlayerStatus m_player;

	int m_gameTime;
	int m_count_levels = 0;
};