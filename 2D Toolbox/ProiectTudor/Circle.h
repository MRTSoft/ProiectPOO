#pragma once
#include "IdealFigure.h"
#include "tinyxml2.h"

//! @brief Implementeaza un cerc modelat matematic
class Circle : public IdealFigure
{
private:
	//! @brief raza cercului
	double m_radius;
public:
	Circle(Point origin = Point(0, 0), double radius = 0.0) : IdealFigure(origin), m_radius(radius) {}
	Circle(Point::pointType ox = 0, Point::pointType oy = 0, double radius = 0) : IdealFigure(ox, oy), m_radius(radius) {}
	Circle(tinyxml2::XMLElement * xmlElem);
	~Circle() {}
	double area();

	//! @brief Circumferinta cercului
	double perimeter();

	//! @brief Afiseaza informatii despre obiect la un stream
	void print(std::ostream & g);


	//! @brief Transforma un cerc intr-un poligon regulat cu p_rezolution laturi
	//! Poligonul este INSCRIS in cercul initial deci are aria si perimetru mai mici decat originalul
	ConvexPolygon * rasterize(unsigned p_resolution = IF_RASTER_REZOLUTION);

	//! @brief Creeaza un nod XML care contine informatii despre obiectul curent
	//! Nodul XML nu este atasat documentului xml
	//! @param xmlDoc - Documentul caruia apartine nodul generat
	virtual tinyxml2::XMLNode * serialize(tinyxml2::XMLDocument &xmlDoc);
protected:


};