#pragma once
#include "StaticIcon.h"

class Gift : public StaticIcon
{
public:
	virtual void collide(Icon* object);
	virtual void collide(Mouse* object);
	virtual void collide(Cat* object) {};

private:

};
