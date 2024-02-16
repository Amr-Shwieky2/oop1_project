#pragma once
#include "Icon.h"

enum Direction { RIGHT, DOWN, LEFT, UP };


const int DIFF_SIZE = 5; //???
const float SWITCH_FRAME = 15; ///???
const float REGULAR_SPEED = 120;//????


class DynamicIcon : public Icon
{
public:
	DynamicIcon() = default;
	

	virtual void move(sf::Clock& clock, sf::Vector2f boardSize) {} //?????

	void draw(sf::RenderWindow& window, float passedTime);//!!

	sf::Vector2f getStartPosition()const;
	sf::Vector2f getPosition()const;
	Direction getDirection()const;
	sf::Vector2f getNextDirection(Direction direction);

protected:
	sf::Vector2f m_startPosition;
	sf::Vector2f m_position;
	Direction m_direction;

	float m_frameCounter = 0;//???
	int m_sourceX = 0; //???
};
