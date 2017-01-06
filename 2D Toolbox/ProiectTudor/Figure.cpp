#include <math.h>
#include "Figure.h"

Point::Point()
{
	x = y = 0;
}

Point::Point(pointType p_x, pointType p_y)
{
	x = p_x;
	y = p_y;
}


double Point::distanceTo(const Point & p)
{
	return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
}
