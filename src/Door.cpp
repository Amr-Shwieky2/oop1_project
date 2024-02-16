#include "Door.h"

void Door::collide(Icon* object)
{
	object->collide(this);
}

void Door::collide(Mouse* object)
{
	object->collide(this);
}

void Door::collide(Cat* object)
{
	object->collide(this);
}
