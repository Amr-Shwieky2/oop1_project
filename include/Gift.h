#pragma once
#include "NonMovable.h"
#include "Mouse.h"

class FirstGift;
class SecondGift;
class ThirdGift;

class Gift : public NonMovable
{
public:
	Gift(sf::Vector2f position, GiftType gift) : NonMovable(), m_position(position) {
		m_position = position;
		switch (gift)
		{
		case AddHeart: std::make_unique<FirstGift>(); break;
		case RemoveCat: std::make_unique<SecondGift>(); break;
		case AddTime: std::make_unique<ThirdGift>(); break;
		default: break;
		}
	};

	virtual void collide(Icon* object) { object->collide(this); };
	virtual void collide(Mouse* object) { object->collide(this); };
	virtual void collide(Cat* object) {};

	

protected:
	sf::Vector2f m_position;
};
