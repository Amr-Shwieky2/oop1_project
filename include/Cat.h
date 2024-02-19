#pragma once
#include "Movable.h"
#include <vector>
#include <memory>

class Cat : public Movable
{
public:
	Cat();
	
	virtual void move(float passedTime, sf::Vector2f boardSize, const std::vector<std::vector<sf::Vector3i>>& Tree) {}; //???!!

	virtual void collide(Wall* object);
	virtual void collide(Door* object);

protected:

	//int m_sourceX = 0; //????
	bool m_moving;
	bool m_wallCollision; 
	bool m_doorCollision;
	
};
