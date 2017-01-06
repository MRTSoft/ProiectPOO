#pragma once
#include "IdealFigure.h"

class Circle : public IdealFigure
{
private:
	double m_radius;
public:
	Circle(Point origin = Point(0, 0), double radius = 0.0) : IdealFigure(origin), m_radius(radius) {}
	Circle(Point::pointType ox = 0, Point::pointType oy = 0, double radius = 0) : IdealFigure(ox, oy), m_radius(radius) {}
	~Circle() {}
	double area();
	double perimeter();
	ConvexPolygon rasterize(unsigned p_resolution = IF_RASTER_REZOLUTION);
protected:


};