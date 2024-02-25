#include "PlayerStatus.h"

PlayerStatus::PlayerStatus() {
	m_lifeTexture.loadFromFile("life.png");
	m_lifeSprite.setTexture(m_lifeTexture);
	m_lifeSprite.setScale(28.f / m_lifeTexture.getSize().x, 28.f / m_lifeTexture.getSize().y);
}

void PlayerStatus::draw(sf::RenderWindow& window, int life, int score, int level, int timer, sf::Vector2f BoardSize, sf::Font font) {
	std::string status = "Lives: \nScore " + std::to_string(score) +
						 "in level " + std::to_string(level) + "\nTime Left " +
						 std::to_string(timer) + "Seconds";

	m_statusBar.setPosition(20, BoardSize.x + 5.f);
	m_statusBar.setString(status);
	m_statusBar.setCharacterSize(20);
	m_statusBar.setFont(font);
	m_statusBar.setFillColor(sf::Color::Black);
	window.draw(m_statusBar);

	float textWidth = m_statusBar.getLocalBounds().width;

	// Set the position of the life icon next to the status text
	m_lifeSprite.setPosition(textWidth, BoardSize.x + 2.f);

	for (int i = 0; i < life; i++) {
		window.draw(m_lifeSprite);
		m_lifeSprite.move(32 + 5, 0); // Move the life sprite to the right for the next life
	}
}
