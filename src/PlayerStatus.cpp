#include "PlayerStatus.h"

PlayerStatus::PlayerStatus() {
	m_lifeSprite.setTexture(*(Utilities::instance().getLifeTexture()));
	m_lifeSprite.setTextureRect(sf::IntRect(11 * P_SIZE, 0, P_SIZE, P_SIZE));
}

void PlayerStatus::draw(sf::RenderWindow& window, int life, int score, int level, int timer, sf::Vector2f BoardSize) {
	std::string status = "SCORE " + std::to_string(score) +
						 " LEVEL " + std::to_string(level) + " TIME LEFT " +
						 std::to_string(timer) + " LIFE  ";

	m_statusBar.setPosition(0, BoardSize.x + 5.f);
	m_statusBar.setString(status);
	m_statusBar.setCharacterSize(P_SIZE);
	window.draw(m_statusBar);

	for (int i = 0; i < life; i++) {
		m_lifeSprite.setPosition(m_statusBar.getGlobalBounds().width + i * P_SIZE, BoardSize.x + 10.f);
		window.draw(m_lifeSprite);
	}
}
