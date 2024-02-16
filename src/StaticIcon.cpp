#include "StaticIcon.h"

void StaticIcon::draw(sf::RenderWindow& window, sf::Vector2f pos)
{
	if (getStatus()) {
		//m_sprite.setColor(m_color);
		m_sprite.setPosition(pos);
		window.draw(m_sprite);
	}
}

bool StaticIcon::getStatus() const
{
	return m_status;
}

void StaticIcon::setStatus(bool status)
{
	m_status = status;
}