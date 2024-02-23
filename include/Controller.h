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
	void handleLevelEvents(sf::Clock& clock);


	void buttonReleased(sf::Event);

	void openLevel(int, int, unsigned int, Board&);

	void openInformation();

	int checkSoundIconPressed(int val);
	//sf::Vector2i checkButtons(sf::Vector2i vaL);
	int checkButtons(int val);

	//======================================================================
	int levelsInGame(std::string str);
	void checkCollision(Movable* character, Direction direction, Board& board);
	void moveDynamic(float passedTime, Board& board);
	bool catchMouse(Cat* cat);
	void reternStartingPosition();
	bool isMouseDied();
	bool finshCheese();// noor add the logic
	void draw(float passedTime, Board& board);
	void movableDraw(float passedTime);
	//======================================================================

	bool m_mainPage = true;
	bool m_newGame = false;
	bool m_scoreTable = false;
	bool m_mute = false;
	bool m_information = false;

	sf::RenderWindow m_window;
	sf::RenderWindow m_levelWindow;

    Screens m_screens;

	Mouse m_mouse;
	std::vector<std::unique_ptr<Cat>> m_cats;

	PlayerStatus m_player;


	int m_gameTime;
};