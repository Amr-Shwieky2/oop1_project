#pragma once
#include "Movable.h"


#include <vector>
#include <memory>

class Cat : public Movable
{
public:
	Cat();

	virtual void move(float passedTime, sf::Vector2f boardSize, const std::vector<std::vector<sf::Vector3i>>& Tree) = 0;



	virtual void collide(Icon*) {};
	virtual void collide(Mouse*) {};
	virtual void collide(Cat*) {};
	virtual void collide(Cheese*) {};
	virtual void collide(Wall*);
	virtual void collide(Door*);
	virtual void collide(Key*) {};
	virtual void collide(Gift*) {};


protected:
	//int m_sourceX = 0; //????
	bool m_moving;
	bool m_wallCollision;
	bool m_doorCollision;

};