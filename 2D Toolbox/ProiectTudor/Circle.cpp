#include <math.h>
#include "Circle.h"

Circle::Circle(tinyxml2::XMLElement * xmlElem) :IdealFigure(Point(0, 0)), m_radius(0)
{
	//creates a Circle from a XML Element
	if (xmlElem)
	{
		m_radius = xmlElem->DoubleAttribute("radius");
		tinyxml2::XMLElement * originElem = xmlElem->FirstChildElement("Origin");
		if (originElem)
		{
			Point org(originElem->FirstChildElement("Point"));
			IdealFigure::m_origin = org;
		}
	}
}

double Circle::area()
{
	return PI * m_radius * m_radius;
}

double Circle::perimeter()
{
	return 2.0 * PI * m_radius;
}

void Circle::print(std::ostream & g)
{
	g << "[Circle Object]\n\t-Origin (";
	g << m_origin.x << ", "<<m_origin.y;
	g << ")\n\t-Radius " << m_radius;
	g << "\n";
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


