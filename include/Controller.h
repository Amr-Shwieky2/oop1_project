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

	void setSoundBuffers();

	void openLevel(int, int, unsigned int, Board&);

	int checkSoundIconPressed(int val);
	//sf::Vector2i checkButtons(sf::Vector2i vaL);
	int checkButtons(int val);


	int levelsInGame(std::string str);

	bool m_mainPage = true;
	bool m_newGame = false;
	bool m_scoreTable = false;
	bool m_mute = false;

	sf::RenderWindow m_window;
	sf::RenderWindow m_levelWindow;

    Screens m_screens;

	sf::SoundBuffer m_openingSoundBuffer;
	sf::Sound m_openingSound;	
	
	sf::SoundBuffer m_clickSoundBuffer;
	sf::Sound m_clickSound;	
	
	sf::SoundBuffer m_tomSoundBuffer;
	sf::Sound m_tomSound;

	sf::SoundBuffer m_jerrySoundBuffer;
	sf::Sound m_jerrySound;	
	
	sf::SoundBuffer m_catchSoundBuffer;
	sf::Sound m_catchSound;

	Mouse m_mouse;
	std::vector<std::unique_ptr<Cat>> m_cats;
};