#pragma once

#include "Board.h"

class Screens
{
public:
	Screens();

	void draw(sf::RenderWindow&) const;
	void drawBackground(sf::RenderWindow&) const;
	void drawStarter(sf::RenderWindow&) const;

private:
	void setBackground();
	void setOpeningGame();


	sf::Texture m_backgroundTexture; // Texture for the background
	sf::Sprite m_backgroundSprite; // Sprite for the background

	sf::Texture m_startTheGame;
	sf::Sprite m_startTheGameSprite;
	//sf::SoundBuffer m_openingSoundBuffer;
	//sf::Sound m_openingSound;
};

