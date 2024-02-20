#include "NonMovable.h"

bool NonMovable::getStatus() const
{
	return m_status;
}

void NonMovable::setStatus(bool status)
{
	m_status = status;
}

sf::Vector2f NonMovable::getPosition() const
{
	return m_position;
}

void NonMovable::setPosition(sf::Vector2f position)
{
	m_position = position;
}

void NonMovable::draw(sf::RenderWindow& window, sf::Vector2f pos)
{
	if (m_status) {
		//m_sprite.setColor(m_color);
		m_sprite.setPosition(pos);
		window.draw(m_sprite);
	}
}
