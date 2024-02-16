#pragma once
#include "StaticIcon.h"

class Cheese : public StaticIcon
{
public:

	virtual void collide(Icon* object);
	virtual void collide(Mouse* object);
	virtual void collide(Cat* object) {};

private:

};
