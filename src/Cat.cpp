#include "Cat.h"

Cat::Cat() : m_doorCollision(false), m_wallCollision(false), m_moving(false) {
    m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(CAT)));
    m_sprite.setOrigin(getCenter(m_sprite.getPosition()));
    SetPosition(m_sprite.getOrigin());
    m_direction = RIGHT;
}

void Cat::collide(Wall* object) {
	m_sprite.setPosition(getCenter(m_previousPostion));
	m_wallCollision = true;
}

void Cat::collide(Door* object) {
	m_sprite.setPosition(getCenter(m_previousPostion));
	m_doorCollision = true;
}
