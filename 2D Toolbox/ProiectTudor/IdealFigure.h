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

	/*! NOTE Functia nu pastreaza Aria/Perimetrul figurii dar este garantat ca va da tot timpul
	 *  Un poligon convex inscris in figura data deci cu aria mai mica sau egala
	 *  O valoare mai mare de 50 va da rezultate destul de bune dpdv vizual
	*/
	virtual void print(std::ostream & g) = 0;
	virtual ConvexPolygon * rasterize(unsigned rezolution) = 0;
	virtual tinyxml2::XMLNode * serialize(tinyxml2::XMLDocument &xmlDoc);
	
protected:
	Point m_origin;
private:

};