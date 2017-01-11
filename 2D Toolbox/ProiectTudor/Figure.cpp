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

Point::Point(tinyxml2::XMLElement * elem)
{
	x = y = 0;
	if (elem)
	{
		x = elem->DoubleAttribute("x");
		y = elem->DoubleAttribute("y");
	}
}


void Point::print(std::ostream & g)
{
	g << "[Point Object] -> (";
	g << x << ", " << y << ")\n";
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
