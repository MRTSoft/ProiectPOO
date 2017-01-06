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

tinyxml2::XMLNode * Point::serialize(tinyxml2::XMLDocument & xmlDoc)
{
	tinyxml2::XMLElement * xmlPoint = xmlDoc.NewElement("Point");
	xmlPoint->SetAttribute("x", this->x);
	xmlPoint->SetAttribute("y", this->y);
	return xmlPoint;
}
