#include "PointSet.h"

double PointSet::area()
{
	return 0.0;
}

double PointSet::perimeter()
{
	return 0.0;
}

Point PointSet::getMedianPoint()
{
	Point::pointType sum_x = 0, sum_y = 0;
	List<Point>::listElem * p = m_points.getHead();
	while (p != nullptr)
	{
		sum_x += p->data.x;
		sum_y += p->data.y;
		p = p->next;
	}
	
	Point med;
	med.x = sum_x / m_nr;
	med.y = sum_y / m_nr;
	return med;
}

unsigned PointSet::getPointNr()
{
	return m_nr;
}

List<Point> PointSet::getPointsList()
{
	return m_points;
}

PointSet::PointSet(): m_points(), m_nr(0) { 

}

PointSet::PointSet(const List<Point>& lst, const unsigned lst_count)
{
	m_points = lst;
	m_nr = lst_count;
}

PointSet::~PointSet()
{
	//Nothing to do here
}




