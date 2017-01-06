#pragma once
#include "ConvexPolygon.h"

#define IF_RASTER_REZOLUTION 20
class IdealFigure : public Figure
{
public:
	~IdealFigure() {};
	virtual ConvexPolygon rasterize(unsigned pointsNr = IF_RASTER_REZOLUTION) = 0;
protected:
	Point m_origin;
private:

};