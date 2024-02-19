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
	void handleEvents(sf::Event);

	void buttonReleased(sf::Event event);

	void setSoundBuffers();

	int checkSoundIconPressed(int val);
	//sf::Vector2i checkButtons(sf::Vector2i vaL);
	int checkButtons(int val);


	int levelsInGame(std::string str);

	bool m_mainPage = true;
	bool m_mute = false;

	//Board m_board;
	sf::RenderWindow m_window;
    Screens m_screens;


	sf::SoundBuffer m_openingSoundBuffer;
	sf::Sound m_openingSound;	
	
	sf::SoundBuffer m_clickSoundBuffer;
	sf::Sound m_clickSound;	
	
	//sf::SoundBuffer m_openingSoundBuffer;
	//sf::Sound m_openingSound;
};