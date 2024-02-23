#pragma once

#include "Board.h"

const int SOUNDS = 5;
const int STORY_SCREENS = 8;

enum Sounds {OPEN , CLICK, TOMRUN, CATCH};

class Screens
{
public:
	Screens();

	//void draw(sf::RenderWindow&) const;
	void drawBackground(sf::RenderWindow&);
	void drawStarterSection(sf::RenderWindow&);
	void drawSoundButton(sf::RenderWindow&, bool);
	void drawInformation(sf::RenderWindow&);
	void drawStory(sf::RenderWindow&, unsigned int, float, int);
	void drawLevelOpenning(sf::RenderWindow&, unsigned int);

	void playPauseSound(int, bool);
	void OpeningBackground(sf::RenderWindow&);

	void setLevelsOpenings(float, float, unsigned int);

	sf::Font getFont() const;


private:
	//void drawStarter(sf::RenderWindow&) const;
	void drawStarter(sf::RenderWindow& window, int spriteIndex) const;
	sf::Text createText(const std::string&, const sf::Font&, unsigned int);
	void drawTextInStarter(sf::Text&, sf::RenderWindow&, int);
	//sf::Text createText(std::string, sf::Font, unsigned int, sf::RenderWindow&);

	void setBackground();
	void setCounters();
	void setOpeningGame();
	void setMenu();
	void setInformation();
	void setSoundTexture();
	void setSoundBuffers();
	void setStory();

	std::vector<sf::Texture> m_levelsBackgroundsTexture;
	std::vector<sf::Sprite> m_levelsBackgroundsSprite;

	sf::Texture m_countersTexture[5];
	sf::Sprite m_countersSprite[5];

	sf::Texture m_backgroundTexture; // Texture for the background
	sf::Sprite m_backgroundSprite; // Sprite for the background

	sf::Texture m_startTheGame;
	sf::Sprite m_startTheGameSprite;

	sf::Text m_newGameText, m_tableText, m_exitText;

	std::string m_informationTextStr;
	sf::Text m_informationText;

	sf::Texture m_soundOn, m_soundOff;
	sf::Sprite m_soundOnSprite, m_soundOffSprite;

	sf::Texture m_skipTexture;
	sf::Sprite m_skipSprite;

	sf::SoundBuffer m_soundBuffer[SOUNDS];
	sf::Sound m_sound[SOUNDS];

	sf::Font m_font;

	sf::Texture m_storyTexture[STORY_SCREENS];
	sf::Sprite m_storySprite[STORY_SCREENS];
};

