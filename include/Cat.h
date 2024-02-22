#pragma once
#include "Movable.h"
#include "NonMovable.h"

#include <vector>
#include <memory>

class Board;

class Cat : public Movable
{
public:
	Cat();
	
	virtual void move(float passedTime, sf::Vector2f boardSize, const std::vector<std::vector<sf::Vector3i>>& Tree) = 0;
	/*virtual std::vector<std::vector<sf::Vector3i>> getBfsTree(sf::Vector2i start, 
		const std::vector<std::vector<std::unique_ptr<NonMovable>>>& NonMovableIcon,
		Board& board);*/

	virtual void collide(Icon* object) {};
	virtual void collide(Mouse* object) {};
	virtual void collide(Cat* object) {};
	virtual void collide(Cheese* object) {};
	virtual void collide(Wall* object);
	virtual void collide(Door* object);
	virtual void collide(Key* object) {};
	virtual void collide(Gift* object) {};
	

protected:

	//int m_sourceX = 0; //????
	bool m_moving;
	bool m_wallCollision; 
	bool m_doorCollision;
	
};
