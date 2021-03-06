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

PointSet::PointSet(tinyxml2::XMLElement * xmlElem)
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

PointSet::~PointSet()
{
	//Nothing to do here
}

tinyxml2::XMLNode * PointSet::serialize(tinyxml2::XMLDocument & xmlDoc)
{
	tinyxml2::XMLElement * xmlPts = xmlDoc.NewElement("PointSet");
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

void PointSet::print(std::ostream & g)
{
	g << "[Point Set Object]";
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




