#pragma once

#include "Screens.h"
#include <thread>

class Controller
{
public:
	Controller();
	//~Controller();

private:
	void handleEvents(sf::Event);

	int levelsInGame(std::string str);


	//Board m_board;
	sf::RenderWindow m_window;
    Screens m_screens;
};