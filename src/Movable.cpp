#include "Movable.h"
#include <math.h>

Movable::Movable(){}

void Movable::draw(sf::RenderWindow& window, float)
{
	
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
	sf::Vector2f nextPosition2;

	switch (direction)
	{
	case UP:
		nextPosition2 = sf::Vector2f(nextPosition.x, nextPosition.y - (P_SIZE / 2));
		return nextPosition2;
	case DOWN:
		nextPosition2 = sf::Vector2f(nextPosition.x, nextPosition.y + (P_SIZE / 2));
		return nextPosition2;
	case RIGHT:
		nextPosition2 = sf::Vector2f(nextPosition.x + (P_SIZE / 2), nextPosition.y);
		return nextPosition2;
	case LEFT:
		nextPosition2 = sf::Vector2f(nextPosition.x - (P_SIZE / 2), nextPosition.y);
		return nextPosition2;
	}
	return nextPosition;
}

//sf::FloatRect Movable::getNextGlobalBounds(float moveDistance) const {
//	sf::FloatRect nextBounds = m_sprite.getGlobalBounds();
//	switch (m_newDirection) {
//	case UP:
//		nextBounds.top -= moveDistance;
//		break;
//	case DOWN:
//		nextBounds.top += moveDistance;
//		break;
//	case RIGHT:
//		nextBounds.left += moveDistance;
//		break;
//	case LEFT:
//		nextBounds.left -= moveDistance;
//		break;
//	}
//	return nextBounds;
//}

void Movable::SetPosition(sf::Vector2f newPosition)
{
	m_sprite.setPosition(newPosition);
}

bool Movable::isCentered(sf::Vector2f position, sf::Vector2f centerPosition)const 
{
	return abs(position.x - centerPosition.x) < COLLISION_SIZE && abs(position.y - centerPosition.y) < COLLISION_SIZE;
}

sf::Vector2f Movable::getCenter(sf::Vector2f position) const {
	sf::Vector2f newPosition;
	newPosition.x = (position.x - ((int)position.x % P_SIZE));
	newPosition.y = (position.y - ((int)position.y % P_SIZE));
	return newPosition;
}

bool Movable::outOfBoard(sf::Vector2f BoardSize) //V
{
	return m_sprite.getPosition().x < BoardSize.x - P_SIZE && m_sprite.getPosition().y < BoardSize.y - P_SIZE &&
		m_sprite.getPosition().x > 0  && m_sprite.getPosition().y > 0 ;
}

void Movable::moveDirection(float moveDistance)
{
	switch (m_direction)
	{
	case UP:
		m_sprite.move(0, -moveDistance);
		//m_sprite.setRotation(270); // Or use setScale for flipping
		break;
	case DOWN:
		m_sprite.move(0, moveDistance);
		//m_sprite.setRotation(90); // Adjust accordingly
		break;
	case RIGHT:
		m_sprite.move(moveDistance, 0);
		//m_sprite.setScale(1.f, 1.f); // Original orientation
		break;
	case LEFT:
		m_sprite.move(-moveDistance, 0);
		//m_sprite.setScale(-1.f, 1.f); // Flipped orientation
		break;
	}
}


