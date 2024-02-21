#pragma once

#include "Screens.h"
#include <thread>



class Controller
{
public:
	Controller();
	//~Controller();

private:
	void startTheGame();
	void handleMainEvents();
	void handleLevelEvents();


	void buttonReleased(sf::Event);

	void openLevel(int, int, unsigned int);

	void openInformation();

	int checkSoundIconPressed(int val);
	//sf::Vector2i checkButtons(sf::Vector2i vaL);
	int checkButtons(int val);


	int levelsInGame(std::string str);

	void checkCollision(Movable* character, Direction direction);
	void moveDynamic(float passedTime);

	void reternStartingPosition();
	void draw(float passedTime);
	void drawMovable(float passedTime);

	bool m_mainPage = true;
	bool m_newGame = false;
	bool m_scoreTable = false;
	bool m_mute = false;
	bool m_information = false;
	bool m_inGame = false;
	float m_passedTime;

	sf::RenderWindow m_window;
	sf::RenderWindow m_levelWindow;

    Screens m_screens;
	Board* m_board;
	Mouse m_mouse;
	std::vector<std::unique_ptr<Cat>> m_cats;
};