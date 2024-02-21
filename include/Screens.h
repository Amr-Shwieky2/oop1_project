#pragma once

#include "Board.h"

const int Sounds = 4;

enum Sounds {OPEN , CLICK, TOMRUN, CATCH};

class Screens
{
public:
	Screens();

	//void draw(sf::RenderWindow&) const;
	void drawBackground(sf::RenderWindow&);
	void drawStarterSection(sf::RenderWindow&);
	void drawSoundButton(sf::RenderWindow&, bool);
	void playPauseSound(int, bool);
	void OpeningBackground(sf::RenderWindow&);




private:
	//void drawStarter(sf::RenderWindow&) const;
	void drawStarter(sf::RenderWindow& window, int spriteIndex) const;
	sf::Text createText(const std::string&, const sf::Font&, unsigned int);
	void drawTextInStarter(sf::Text&, sf::RenderWindow&, int);
	//sf::Text createText(std::string, sf::Font, unsigned int, sf::RenderWindow&);

	void setBackground();
	void setCounters();
	void setOpeningGame();
	void setInformation();
	void setSoundTexture();
	void setSoundBuffers();

	//Board m_board;
	sf::Texture m_countersTexture[5];
	sf::Sprite m_countersSprite[5];

	sf::Texture m_backgroundTexture; // Texture for the background
	sf::Sprite m_backgroundSprite; // Sprite for the background

	sf::Texture m_startTheGame;
	sf::Sprite m_startTheGameSprite;

	sf::Text m_newGameText, m_tableText, m_exitText;

	sf::Texture m_soundOn, m_soundOff;
	sf::Sprite m_soundOnSprite, m_soundOffSprite;

	sf::SoundBuffer m_soundBuffer[Sounds];
	sf::Sound m_sound[Sounds];
};

