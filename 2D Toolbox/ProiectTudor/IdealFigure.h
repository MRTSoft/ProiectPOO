#pragma once
#include "ConvexPolygon.h"

//! Rezolutia se refera la cate puncte sunt folosite implicit pentru a converti un cerc intr-un polinom
#define IF_RASTER_REZOLUTION 20
#define PI 3.1415926535897932384626433832795

//! @brief Clasa modeleaza figuri matematice perfecte
class IdealFigure : public Figure
{
public:
	IdealFigure(Point origin = Point(0, 0)) : m_origin(origin) {};
	IdealFigure(Point::pointType ox, Point::pointType oy) : m_origin(ox, oy) {}
	~IdealFigure() {};

	//! @brief Converteste o figura intr-un poligon regulat
	/*! NOTE Functia nu pastreaza Aria/Perimetrul figurii dar este garantat ca va da tot timpul
	 *  Un poligon convex inscris in figura data deci cu aria mai mica sau egala
	 *  O valoare mai mare de 50 va da rezultate destul de bune dpdv vizual
	*/
	virtual ConvexPolygon * rasterize(unsigned rezolution) = 0;

	//! @brief Afiseaza informatii despre obiect la un stream
	virtual void print(std::ostream & g) = 0;
	
	//! @brief Creeaza un nod XML care contine informatii despre obiectul curent
	//! Nodul XML nu este atasat documentului xml
	//! @param xmlDoc - Documentul caruia apartine nodul generat
	virtual tinyxml2::XMLNode * serialize(tinyxml2::XMLDocument &xmlDoc);
	
protected:
	//! Originea figurii in sistemul de coordonate
	Point m_origin;
private:

};