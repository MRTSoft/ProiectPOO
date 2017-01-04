#include "Entity.h"

using namespace ua_misc;

Point Entity::getPosition()
{
	return mPosition;
}

void Entity::setPosition(Point position)
{
	mPosition = position;
}

void Entity::setPosition(pointUnit x, pointUnit y)
{
	mPosition.x = x;
	mPosition.y = y;
}
