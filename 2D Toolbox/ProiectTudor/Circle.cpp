#include <math.h>
#include "Circle.h"

double Circle::area()
{
	return PI * m_radius * m_radius;
}

double Circle::perimeter()
{
	return 2.0 * PI * m_radius;
}

ConvexPolygon Circle::rasterize(unsigned p_resolution)
{
	List<Point> points;
	Point p;
	double increment = 2 * PI / p_resolution;
	double t = 0;
	for (unsigned i = 0; i < p_resolution; ++i)
	{
		p.x = m_origin.x + m_radius * cos(t);
		p.y = m_origin.y + m_radius * sin(t);
		t += increment;
		points.insert(p);
	}
	
	return ConvexPolygon(points, p_resolution);
}

tinyxml2::XMLNode * Circle::serialize(tinyxml2::XMLDocument & xmlDoc)
{
	tinyxml2::XMLElement * xmlCircle = xmlDoc.NewElement("Circle");
	xmlCircle->SetAttribute("radius", m_radius);
	xmlCircle->InsertFirstChild(IdealFigure::serialize(xmlDoc));
	return xmlCircle;
}
