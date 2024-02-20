#pragma once
#include "Icon.h"

class NonMovable : public Icon
{
public:
	NonMovable() : m_status(true) {};

	bool getStatus()const;
	void setStatus(bool status);

	sf::Vector2f getPosition()const;
	void setPosition(sf::Vector2f position);

	virtual void draw(sf::RenderWindow& window, sf::Vector2f pos) {};

	virtual void collide(Icon* object) {};
	virtual void collide(Mouse* object) {};
	virtual void collide(Cat* object) {};//??

	virtual void collide(Cheese* object) {};
	virtual void collide(Wall* object) {};
	virtual void collide(Door* object) {};
	virtual void collide(Key* object) {};
	virtual void collide(Gift* object) {};

protected:
	bool m_status;
	sf::Vector2f m_position;
};

