#pragma once
#include "ConvexPolygon.h"

#define IF_RASTER_REZOLUTION 20
#define PI 3.1415926535897932384626433832795
class IdealFigure : public Figure
{
public:
	IdealFigure(Point origin = Point(0, 0)) : m_origin(origin) {};
	IdealFigure(Point::pointType ox, Point::pointType oy) : m_origin(ox, oy) {}
	~IdealFigure() {};
	virtual ConvexPolygon rasterize(unsigned rezolution) = 0;

	
protected:
	Point m_origin;
private:

};