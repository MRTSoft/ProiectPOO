#include <math.h>
#include "ConvexPolygon.h"

double triangleArea(Point a, Point b, Point c)
{
	double ab = a.distanceTo(b);
	double ac = a.distanceTo(c);
	double bc = b.distanceTo(c);
	double p = (ab + ac + bc) / 2.0;//semiperimetru
	return (sqrt(p*(p - ab)*(p - ac)*(p - bc)));
}

ConvexPolygon::ConvexPolygon(List<Point> lst, unsigned lst_count) : PointSet(lst, lst_count)
{

}

double ConvexPolygon::area()
{
	double r_area = 0.0;
	if (m_nr >= 3)
	{
		//Daca avem mai putin de 3 puncte nu avem un poligon propriu zis
		//Daca avem cel putin 3 puncte putem calcula aria ca fiind o suma de triunghiuri
		List<Point>::listElem * p = m_points.getHead();
		Point A = p->data;
		p = p->next;
		Point B = p->data;
		p = p->next;
		Point C = p->data;
		p = p->next;
		r_area += triangleArea(A, B, C);
		while (p != nullptr)
		{
			B = C;
			C = p->data;
			p = p->next;
			r_area += triangleArea(A, B, C);
		}
	}
	return r_area;
}

double ConvexPolygon::perimeter()
{
	double r_perim = 0.0;
	if (m_nr >= 2)
	{
		List<Point>::listElem * p = m_points.getHead();
		Point A = p->data;
		Point O = A;
		p = p->next;
		Point B = p->data;
		p = p->next;
		r_perim += A.distanceTo(B);
		while (p != nullptr)
		{
			A = B;
			B = p->data;
			p = p->next;
			r_perim += A.distanceTo(B);
		}
		r_perim += O.distanceTo(B);
	}
	return r_perim;
}
