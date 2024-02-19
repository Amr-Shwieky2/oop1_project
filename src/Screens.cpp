#include "Screens.h"

Screens::Screens() {
	setOpeningGame();
	setBackground();
}

void Screens::setBackground() {
	m_backgroundTexture.loadFromFile("Tom&Jerry.png");
	m_backgroundSprite.setScale((float)(40 * P_SIZE) / m_backgroundTexture.getSize().x,
		(float)(22 * P_SIZE) / m_backgroundTexture.getSize().y);
	m_backgroundSprite.setTexture(m_backgroundTexture);

}
void Screens::setOpeningGame() {
	m_startTheGame.loadFromFile("startGame.png");
	m_startTheGameSprite.setTexture(m_startTheGame);
	// Set the origin of the sprite to its center
	m_startTheGameSprite.setOrigin(m_startTheGameSprite.getLocalBounds().width / 2, m_startTheGameSprite.getLocalBounds().height / 2);
	// Set the position of the sprite to the center of the window
	m_startTheGameSprite.setPosition(640, 350);
	//m_openingSoundBuffer.loadFromFile("opening.wav");
	//m_openingSound.setBuffer(m_openingSoundBuffer);
}

void Screens::drawStarter(sf::RenderWindow& window) const {
	window.draw(m_startTheGameSprite);
}

void Screens::drawBackground(sf::RenderWindow& window) const {
	window.draw(m_backgroundSprite);
}

//void Screens::draw(sf::RenderWindow& window) const {
//	window.draw(m_backgroundSprite);
//}
//
//void Screens::draw(sf::RenderWindow& window) const {
//	window.draw(m_backgroundSprite);
//}
