#pragma once
#include "NonMovable.h"
#include "Mouse.h"

class Cheese : public NonMovable
{
public:
	Cheese() : NonMovable() {
		m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(CHEESE)));
		m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
			((float)P_SIZE / m_sprite.getGlobalBounds().height)));
	};

	virtual void collide(Icon* object) { object->collide(this); };
	virtual void collide(Mouse* object) { object->collide(this); };
	virtual void collide(Cat*) {};
	
	

private:
	
};
