#include <math.h>
#include "Ellipse.h"

double Ellipse::area()
{
	return PI * m_a * m_b;
}

double Ellipse::perimeter()
{
	//Ramanujan approximation taken from https://en.wikipedia.org/wiki/Ellipse#Area
	return (PI * (3.0 * (m_a + m_b) - sqrt((3.0 * m_a + m_b) * (m_a + 3.0 * m_b))));
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


