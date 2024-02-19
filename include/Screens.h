#pragma once

#include "Board.h"

class Screens
{
public:
	Screens();

	//void draw(sf::RenderWindow&) const;
	void drawBackground(sf::RenderWindow&) const;
	void drawStarterSection(sf::RenderWindow& window);
	void drawMap(sf::RenderWindow& window);
	void OpeningBackground(sf::RenderWindow&);


private:
	void drawStarter(sf::RenderWindow&) const;
	sf::Text createText(std::string, sf::Font, unsigned int, sf::RenderWindow&);

	void setBackground();
	void setOpeningGame();

	Board m_board;

	sf::Texture m_backgroundTexture; // Texture for the background
	sf::Sprite m_backgroundSprite; // Sprite for the background

	sf::Texture m_startTheGame;
	sf::Sprite m_startTheGameSprite;
	//sf::SoundBuffer m_openingSoundBuffer;
	//sf::Sound m_openingSound;
};

