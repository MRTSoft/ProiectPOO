#include <iostream>
#include <iomanip>
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

ConvexPolygon::ConvexPolygon(tinyxml2::XMLElement * xmlElem)
{
	m_points = List<Point>();
	m_nr = 0;
	if (xmlElem)
	{
		tinyxml2::XMLElement * pointElemIterator = xmlElem->LastChildElement("Point");
		m_nr = xmlElem->UnsignedAttribute("count");
		while (pointElemIterator)
		{
			m_points.insert(Point(pointElemIterator));
			pointElemIterator = pointElemIterator->PreviousSiblingElement("Point");
		}
	}
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

void ConvexPolygon::print(std::ostream & g)
{
	g << "[Convex Polygon Object]";
	g << "\n\t-Count " << m_nr;
	List<Point>::listElem * p = m_points.getHead();
	g << "\n";
	while (p != nullptr)
	{
		g << "\t";
		p->data.print(g);
		p = p->next;
	}
}

tinyxml2::XMLNode * ConvexPolygon::serialize(tinyxml2::XMLDocument & xmlDoc)
{
	tinyxml2::XMLElement * xmlPts = xmlDoc.NewElement("ConvexPolygon");
	xmlPts->SetAttribute("count", m_nr);
	List<Point>::listElem * p = m_points.getHead();
	if (p != nullptr)
	{
		tinyxml2::XMLNode * xmlPt = p->data.serialize(xmlDoc);
		tinyxml2::XMLNode * xmlCurrent = xmlPts->InsertFirstChild(xmlPt);
		p = p->next;
		while (p != nullptr)
		{
			tinyxml2::XMLNode * xmlPt = p->data.serialize(xmlDoc);
			xmlCurrent = xmlPts->InsertAfterChild(xmlCurrent, xmlPt);
			p = p->next;
		}
	}
	return xmlPts;
}

void ConvexPolygon::dbg_print_points(std::ostream & g)
{
	List<Point>::listElem* pts = m_points.getHead();
	Point first = pts->data;
	g << "x = [];" << std::endl;
	g << std::setprecision(20);
	while (pts != nullptr)
	{
		g << "x = [x " << pts->data.x << "];" << std::endl;
		if (pts->next != nullptr)
			g << " ";
		pts = pts->next;
	}
	g << "x = [x " << first.x << "];" << std::endl;

	pts = m_points.getHead();
	g << "y = [];" << std::endl;
	//g << std::setprecision(2);
	while (pts != nullptr)
	{
		g << "y = [y " << pts->data.y << "];" << std::endl;
		if (pts->next != nullptr)
			g << " ";
		pts = pts->next;
	}
	g << "y = [y " << first.y << "];" << std::endl;
	g << "plot(x,y)" << std::endl;
}

