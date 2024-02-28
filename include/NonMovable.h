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

	virtual void draw(sf::RenderWindow& window, sf::Vector2f pos);
	sf::FloatRect getGlobalBounds() const;

	virtual void collide(Cheese*) {};
	virtual void collide(Wall*) {};
	virtual void collide(Door*) {};
	virtual void collide(Key*) {};
	virtual void collide(Gift*) {};

protected:
	bool m_status;
	sf::Vector2f m_position;
};

