#include "NonMovable.h"

void NonMovable::draw(sf::RenderWindow& window, sf::Vector2f pos)
{
	if (getStatus()) {
		//m_sprite.setColor(m_color);
		m_sprite.setPosition(pos);
		window.draw(m_sprite);
	}
}

bool NonMovable::getStatus() const
{
	return m_status;
}

void NonMovable::setStatus(bool status)
{
	m_status = status;
}