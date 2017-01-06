#pragma once
#include "PointSet.h"
#include <iostream>

class ConvexPolygon : public PointSet
{
public:
	ConvexPolygon(List<Point> lst = List<Point>(), unsigned lst_count = 0);
	double area();
	double perimeter();
	virtual tinyxml2::XMLNode *	serialize(tinyxml2::XMLDocument & xmlDoc);
	void dbg_print_points(std::ostream &g);

	
protected:

private:

};