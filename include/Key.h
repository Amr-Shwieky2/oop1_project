#pragma once
#include "NonMovable.h"
#include "Mouse.h"

class Key : public NonMovable
{
public:
	Key() : NonMovable() {};
	virtual void collide(Icon* object) { object->collide(this); };
	virtual void collide(Mouse* object) { object->collide(this); };
	virtual void collide(Cat* object) {};

	sf::Vector2i getPosition()const { return m_position; };

private:
	sf::Vector2i m_position;
};
