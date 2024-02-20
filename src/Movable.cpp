#include "Movable.h"
#include <math.h>

Movable::Movable(): m_frameCounter(0), m_sourceX(0)
{
}

void Movable::draw(sf::RenderWindow& window, float passedTime)
{
	m_frameCounter += passedTime * REGULAR_SPEED;
	if (m_frameCounter > SWITCH_FRAME)
	{
		m_frameCounter = 0;
		m_sourceX++;
	}
	m_sprite.setTextureRect(sf::IntRect(m_sourceX * P_SIZE, m_direction * P_SIZE, P_SIZE, P_SIZE));//change the why 
	window.draw(m_sprite);
}

sf::Vector2f Movable::getStartPosition() const
{
	return m_startPosition;
}

sf::Vector2f Movable::getPosition() const
{
	return m_position;
}

void Movable::setStartPosition(sf::Vector2f position)
{
	m_startPosition = position;
}

Direction Movable::getDirection() const
{
	return m_direction;
}

sf::Vector2f Movable::getNextDirection(Direction direction)
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

void Movable::SetPosition(sf::Vector2f newPosition)
{
	m_sprite.setPosition(getCenter(newPosition));
}

bool Movable::isCentered(sf::Vector2f position, sf::Vector2f centerPosition)
{
	return abs(position.x - centerPosition.x) < COLLISION_SIZE && abs(position.y - centerPosition.y) < COLLISION_SIZE;
}

bool Movable::outOfBoard(sf::Vector2f size)
{
	int distance = P_SIZE / 2;
	return m_sprite.getPosition().x + distance > size.y || m_sprite.getPosition().y + distance > size.x ||
		m_sprite.getPosition().x - distance < 0 || m_sprite.getPosition().y - distance < 0;
}



sf::Vector2f Movable::getCenter(sf::Vector2f pos)
{
	sf::Vector2f newPostion;
	newPostion.x = (pos.x - ((int)pos.x % P_SIZE)) + P_SIZE / 2;
	newPostion.y = (pos.y - ((int)pos.y % P_SIZE)) + P_SIZE / 2;
	return newPostion;
}

void Movable::moveDirection(float moveDistance)
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


