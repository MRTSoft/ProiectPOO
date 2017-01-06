#pragma once
#include "IdealFigure.h"

class Ellipse : public IdealFigure
{
private:
	double m_a;
	double m_b;
protected:

public:
	Ellipse(Point origin = Point(0, 0), double a_axis = 0.0, double b_axis = 0.0) : IdealFigure(origin), m_a(a_axis), m_b(b_axis) {}
	Ellipse(double x_origin = 0.0, double y_origin = 0.0, double a_axis = 0.0, double b_axis = 0.0) : IdealFigure(x_origin, y_origin), m_a(a_axis), m_b(b_axis) {}
	~Ellipse() {}
	double area();
	double perimeter();
	ConvexPolygon rasterize(unsigned p_resolution = IF_RASTER_REZOLUTION);

};