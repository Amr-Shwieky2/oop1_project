#pragma once
#include "NonMovable.h"
#include "Mouse.h"

class Wall : public NonMovable
{
public:
	Wall() : NonMovable() {};

	virtual void collide(Icon* object) { object->collide(this); };
	virtual void collide(Mouse* object) { object->collide(this); };

private:

};

