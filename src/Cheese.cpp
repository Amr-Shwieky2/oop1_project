#include "Cheese.h"

void Cheese::collide(Icon* object)
{
	object->collide(this);
}

void Cheese::collide(Mouse* object)
{
	object->collide(this);
}
