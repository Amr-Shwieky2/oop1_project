#pragma once
#include <SFML\Graphics.hpp>
#include "Utilities.h"

class PlayerStatus
{
public:
	PlayerStatus();
	void draw(sf::RenderWindow& window, int life, int score, int level, int timer, sf::Vector2f BoardSize);

private:
	sf::Text m_statusBar;
	//sf::Font m_font; //????
	sf::Sprite m_lifeSprite;
};
