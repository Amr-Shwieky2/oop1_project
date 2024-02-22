#pragma once
#include "Icon.h"

enum Direction { RIGHT, DOWN, LEFT, UP };


const int COLLISION_SIZE = 5; // to check varibels  Collision
const float SWITCH_FRAME = 15; ///???
const float REGULAR_SPEED = 120;
const float CAT_SPEED = 100; 

class Movable : public Icon
{
public:
	Movable();

	void draw(sf::RenderWindow& window, float passedTime);//!!

	sf::Vector2f getStartPosition()const;
	sf::Vector2f getPosition()const;
	void setStartPosition(sf::Vector2f position);
	Direction getDirection()const;
	sf::Vector2f getNextDirection(Direction direction);

	void SetPosition(sf::Vector2f newPosition);

protected:
	sf::Vector2f m_startPosition;
	sf::Vector2f m_position;
	Direction m_direction;

	Direction m_newDirection;
	sf::Vector2f m_previousPostion;

	float m_frameCounter;//???
	int m_sourceX; //???

	sf::Vector2f getCenter(sf::Vector2f position);
	bool isCentered(sf::Vector2f position, sf::Vector2f centerPosition); // change the name of the function
	bool outOfBoard(sf::Vector2f size); // change the name of the function 
	void moveDirection(float moveDistance);
};
