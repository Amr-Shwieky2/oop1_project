#pragma once
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <fstream>
#include <iostream>


#include "Icon.h"


//enum MouseSound { MUNCH, DEATH, HEALTH_GIFT, TIME_GIFT, DELETE };
//enum gameSound { LEVEL_UP, GAME_OVER };

const int NUM_OF_CHARACTERS = 7;
const int NUM_OF_SCREENS = 7; // noor you want to change this 

class Utilities
{
public:
	sf::Texture* getCharactersTexture(size_t shape);
	sf::Texture* getScreen(size_t screen);
	sf::Texture* getLifeTexture();

	static Utilities& instance();

private:
	Utilities();
	sf::Texture m_CharactersTexture[NUM_OF_CHARACTERS];
	sf::Texture m_Screeen[NUM_OF_SCREENS];

	sf::Texture m_lifeCounter;
};

