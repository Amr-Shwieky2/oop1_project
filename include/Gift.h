#pragma once
#include "NonMovable.h"
#include "Mouse.h"

class Gift : public NonMovable
{
public:
	Gift(sf::Vector2f position) : NonMovable() { 
		m_position = position; 
		m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(GIFT)));
		m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
			((float)P_SIZE / m_sprite.getGlobalBounds().height)));
	};

	virtual void collide(Icon* object) { object->collide(this); };
	virtual void collide(Mouse* object) { object->collide(this); };
	virtual void collide(Cat* object) {};

	

private:
	
};
