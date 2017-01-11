#pragma once
#include "PointSet.h"
#include <iostream>

class ConvexPolygon : public PointSet
{
public:
	ConvexPolygon(List<Point> lst = List<Point>(), unsigned lst_count = 0);
	ConvexPolygon(tinyxml2::XMLElement * xmlElem);
	double area();
	double perimeter();
	void print(std::ostream & g);
	virtual tinyxml2::XMLNode *	serialize(tinyxml2::XMLDocument & xmlDoc);
	void dbg_print_points(std::ostream &g);

	
protected:

private:

};