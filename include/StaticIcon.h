#pragma once
#include "Icon.h"

class StaticIcon : public Icon
{
public:
	StaticIcon() :m_status(true) {};
	void draw(sf::RenderWindow& window, sf::Vector2f pos);

	bool getStatus()const;
	void setStatus(bool status);

	virtual void collide(Cheese* object) {};
	virtual void collide(Wall* object) {};
	virtual void collide(Door* object) {};
	virtual void collide(Key* object) {};
	virtual void collide(Gift* object) {};

protected:
	bool m_status;
};

