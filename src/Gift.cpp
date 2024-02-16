#include "Gift.h"

void Gift::collide(Icon* object)
{
	object->collide(this);
}

void Gift::collide(Mouse* object)
{
	object->collide(this);
}
