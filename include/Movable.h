#pragma once
#include "Icon.h"

enum Direction { RIGHT, DOWN, LEFT, UP };


const int COLLISION_SIZE = 16; // to check varibels  Collision
const float SWITCH_FRAME = 15; ///???
const float REGULAR_SPEED = 360;
const float CAT_SPEED = 100; 

class Movable : public Icon
{
public:
	Movable();
	void draw(sf::RenderWindow& window, float passedTime);
	//=========V
	sf::Vector2f getPosition()const;
	void SetPosition(sf::Vector2f newPosition);

	sf::Vector2f getStartPosition()const;
	void setStartPosition(sf::Vector2f position);

	//=========change name 
	Direction getDirection()const;
	sf::Vector2f getNextDirection(Direction direction);

	/*sf::FloatRect getNextGlobalBounds(float moveDistance) const;
	sf::FloatRect getGlobalBounds() const;*/

protected:
	sf::Vector2f m_startPosition;
	sf::Vector2f m_position;
	Direction m_direction; // change name 

	Direction m_newDirection;
	sf::Vector2f m_previousPostion;

	float m_frameCounter;//???
	int m_sourceX; //???

	sf::Vector2f getCenter(sf::Vector2f position)const; // change name of the function 
	bool isCentered(sf::Vector2f position, sf::Vector2f centerPosition)const; // change the name of the function
	bool outOfBoard(sf::Vector2f size); // change the name of the function 
	void moveDirection(float moveDistance);
};
