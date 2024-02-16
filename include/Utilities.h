#pragma once
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <fstream>
#include <iostream>

enum Characters { MOUSE, CAT, CHEESE, WALL, KEY, DOOR, GIFT };
//enum MouseSound { MUNCH, DEATH, HEALTH_GIFT, TIME_GIFT, DELETE };
//enum gameSound { LEVEL_UP, GAME_OVER };

const int NUM_OF_CHARACTERS = 7;

class Utilities
{
public:
	Utilities();
	

private:
	sf::Texture m_CharactersTexture[NUM_OF_CHARACTERS];
};

