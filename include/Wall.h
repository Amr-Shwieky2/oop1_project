#pragma once
#include "NonMovable.h"
#include "Mouse.h"
#include "Cat.h"

class Wall : public NonMovable
{
public:
	Wall() : NonMovable() {
		m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(WALL)));
		m_sprite.setPosition(m_position);
	};

	virtual void collide(Icon* object) { object->collide(this); };
	virtual void collide(Mouse* object) { object->collide(this); };
	virtual void collide(Cat* object) { object->collide(this); };

	void draw(sf::RenderWindow& window, sf::Vector2f pos) {
		if (m_status) {
			//m_sprite.setColor(m_color);
			m_sprite.setPosition(pos);
			window.draw(m_sprite);
		}
	};

private:

};

