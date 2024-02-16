#include "DynamicIcon.h"

void DynamicIcon::draw(sf::RenderWindow& window, float passedTime)
{
	m_frameCounter += passedTime * REGULAR_SPEED;
	if (m_frameCounter > SWITCH_FRAME)
	{
		m_frameCounter = 0;
		m_sourceX++;
	}
	m_sprite.setTextureRect(sf::IntRect(m_sourceX * P_SIZE, m_direction * P_SIZE, P_SIZE, P_SIZE));
	window.draw(m_sprite);
}

sf::Vector2f DynamicIcon::getStartPosition() const
{
	return m_startPosition;
}

sf::Vector2f DynamicIcon::getPosition() const
{
	return m_position;
}

Direction DynamicIcon::getDirection() const
{
	return m_direction;
}

sf::Vector2f DynamicIcon::getNextDirection(Direction direction)
{
	sf::Vector2f nextPosition = m_sprite.getPosition();

	switch (direction)
	{
	case UP:
		return sf::Vector2f(nextPosition.x, nextPosition.y - (P_SIZE / 2));
	case DOWN:
		return sf::Vector2f(nextPosition.x, nextPosition.y + (P_SIZE / 2));
	case RIGHT:
		return sf::Vector2f(nextPosition.x + (P_SIZE / 2), nextPosition.y);
	case LEFT:
		return sf::Vector2f(nextPosition.x - (P_SIZE / 2), nextPosition.y);
	}
}
