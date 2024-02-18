#include "Cat.h"

Cat::Cat() : m_doorCollision(false), m_wallCollision(false), m_moving(false), m_newDirection(RIGHT)
{
    m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(CAT)));
    m_sprite.setOrigin(getCenter(m_sprite.getPosition()));
    SetPosition(m_sprite.getOrigin());
    m_direction = RIGHT;
}

void Cat::collide(Wall* object)
{
	m_sprite.setPosition(getCenter(m_previousPostion));
	m_wallCollision = true;
}

void Cat::collide(Door* object)
{
	m_sprite.setPosition(getCenter(m_previousPostion));
	m_doorCollision = true;
}

void Cat::moveDirection(float moveDistance)
{
    switch (m_direction)
    {
    case UP:
        m_sprite.move(0, -moveDistance);
        break;
    case DOWN:
        m_sprite.move(0, moveDistance);
        break;
    case RIGHT:
        m_sprite.move(moveDistance, 0);
        break;
    case LEFT:
        m_sprite.move(-moveDistance, 0);
        break;
    }
}
