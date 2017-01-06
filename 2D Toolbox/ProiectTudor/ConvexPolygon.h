#pragma once
#include "PointSet.h"
#include <iostream>

class ConvexPolygon : public PointSet
{
public:
	ConvexPolygon(List<Point> lst = List<Point>(), unsigned lst_count = 0);
	double area();
	double perimeter();
	void dbg_print_points(std::ostream &g);

	
protected:

private:

};