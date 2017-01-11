#include <math.h>
#include "Ellipse.h"

Ellipse::Ellipse(tinyxml2::XMLElement * xmlElem) : IdealFigure(Point()), m_a(0), m_b(0)
{
	if (xmlElem)
	{
		//m_radius = xmlElem->DoubleAttribute("radius");
		m_a = xmlElem->DoubleAttribute("a");
		m_b = xmlElem->DoubleAttribute("b");
		tinyxml2::XMLElement * orgElem = xmlElem->FirstChildElement("Origin");
		if (orgElem)
		{
			IdealFigure::m_origin = Point(orgElem->FirstChildElement("Point"));
		}
	}
}

double Ellipse::area()
{
	return PI * m_a * m_b;
}

double Ellipse::perimeter()
{
	//Ramanujan approximation taken from https://en.wikipedia.org/wiki/Ellipse#Area
	return (PI * (3.0 * (m_a + m_b) - sqrt((3.0 * m_a + m_b) * (m_a + 3.0 * m_b))));
}

void Ellipse::print(std::ostream & g)
{
	g << "[Ellipse Object]\n\t-Origin (";
	g << m_origin.x << ", " << m_origin.y;
	g << ")\n\t-Major semiaxis (a): " << m_a;
	g << "\n\t-Minor semiaxis (b): " << m_b;
	g << "\n";
}

ConvexPolygon Ellipse::rasterize(unsigned p_resolution)
{
	List<Point> points;
	Point p;
	double increment = 2 * PI / p_resolution;
	double t = 0;
	for (unsigned i = 0; i < p_resolution; ++i)
	{
		p.x = m_origin.x + m_a * cos(t);
		p.y = m_origin.y + m_b * sin(t);
		t += increment;
		points.insert(p);
	}
	return ConvexPolygon(points, p_resolution);
}

tinyxml2::XMLNode * IdealFigure::serialize(tinyxml2::XMLDocument & xmlDoc)
{
	tinyxml2::XMLElement * xmlOrigin = xmlDoc.NewElement("Origin");
	xmlOrigin->InsertFirstChild(m_origin.serialize(xmlDoc));
	return xmlOrigin;
}

tinyxml2::XMLNode * Ellipse::serialize(tinyxml2::XMLDocument &xmlDoc)
{
	tinyxml2::XMLElement * xmlEllipse = xmlDoc.NewElement("Ellipse");
	xmlEllipse->SetAttribute("a", m_a);
	xmlEllipse->SetAttribute("b", m_b);
	xmlEllipse->InsertFirstChild(IdealFigure::serialize(xmlDoc));
	return xmlEllipse;
}


