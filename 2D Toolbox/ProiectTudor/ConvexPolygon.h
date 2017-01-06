#pragma once
#include "PointSet.h"

class ConvexPolygon : public PointSet
{
public:
	ConvexPolygon(List<Point> lst = List<Point>(), unsigned lst_count = 0);
	double area();
	double perimeter();
protected:

private:

};