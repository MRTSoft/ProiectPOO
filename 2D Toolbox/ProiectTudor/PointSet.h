#pragma once
#include "Figure.h"
#include "List.h"

//! @brief Clasa care reprezinta o multime de puncte
class PointSet : public Figure
{
public:

	Point			getMedianPoint();
	unsigned		getPointNr();
					PointSet();
					PointSet(const List<Point> &lst, const unsigned lst_count);
					PointSet(tinyxml2::XMLElement * xmlElem);
	virtual			~PointSet();

	//! @brief Creeaza un nod XML care contine informatii despre obiectul curent
	//! Nodul XML nu este atasat documentului xml
	//! @param xmlDoc - Documentul caruia apartine nodul generat
	virtual tinyxml2::XMLNode *	serialize(tinyxml2::XMLDocument & xmlDoc);
	//! @brief Afiseaza informatii despre obiect la un stream
	void print(std::ostream & g);
	//! @brief Area of a point is 0; Area of a finite set of points is also 0
	double area();
	//! @brief The perimeter of a set of points is 0
	double perimeter();

protected:
	//! @brief Returneaza lista de puncte
	List<Point>		getPointsList();
	//! @brief Punctele din multime
	List<Point> m_points;
	//! @brief Cardinalul multimii de puncte
	unsigned	m_nr;

private:
};