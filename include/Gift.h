#pragma once
#include "NonMovable.h"
#include "Mouse.h"

class HeartGift;
class HideCatGift;
class TimeGift;

enum TypeGift {
	ADD_HEART_GIFT,
	HIDE_CAT_GIFT,
	ADD_TIME_GIFT
};

class Gift : public NonMovable {
public:
	Gift() : NonMovable() {};

	virtual void collide(Icon* object) { object->collide(this); };
	virtual void collide(Mouse* object) { object->collide(this); };
	virtual void collide(Cat* object) {};

	TypeGift getType() { return m_typegift; };
protected:
	TypeGift m_typegift;
};
