#include "Cat.h"


Cat::Cat() : m_doorCollision(false), m_wallCollision(false), m_moving(false) {
    m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(CAT)));
    m_sprite.setOrigin(getCenter(m_sprite.getPosition()));
	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
    SetPosition(m_sprite.getOrigin());
    m_direction = RIGHT;
}

void Cat::collide(Wall*) {
	m_sprite.setPosition(m_previousPostion);
	m_wallCollision = true;
}

void Cat::collide(Door*) {
	m_sprite.setPosition(m_previousPostion);
	m_doorCollision = true;
}

