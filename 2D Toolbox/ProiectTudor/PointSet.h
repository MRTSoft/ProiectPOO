#pragma once
#include "Figure.h"
#include "List.h"

class PointSet : public Figure
{
public:

	Point			getMedianPoint();
	unsigned		getPointNr();
					PointSet();
					PointSet(const List<Point> &lst, const unsigned lst_count);
	virtual			~PointSet();

	double area();//Area of a point is 0; Area of a finite set of points is also 0
	double perimeter();// The perimeter of a set of points is 0

protected:
	List<Point>		getPointsList();
	List<Point> m_points;
	unsigned	m_nr;

private:
};