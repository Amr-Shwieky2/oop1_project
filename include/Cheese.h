#pragma once
#include "NonMovable.h"
#include "Mouse.h"

class Cheese : public NonMovable
{
public:
	Cheese() : NonMovable() {};
	virtual void collide(Icon* object) { object->collide(this); };
	virtual void collide(Mouse* object) { object->collide(this); };
	virtual void collide(Cat* object) {};
	void draw(sf::RenderWindow& window, sf::Vector2f pos) {
		if (m_status) {
			//m_sprite.setColor(m_color);
			m_sprite.setPosition(pos);
			window.draw(m_sprite);
		}
	};
	

private:
	
};
