#pragma once
#include "NonMovable.h"

class Door : public NonMovable
{
public:
	Door() : NonMovable() {};

	virtual void collide(Icon* object) { object->collide(this); };
	virtual void collide(Mouse* object) { object->collide(this); };
	virtual void collide(Cat* object) { object->collide(this); };

private:

};
