#pragma once
#include "IdealFigure.h"


//! @brief Clasa implementeaza o elipsa matematica
//! Elipsa este reprezentata prin origine si cele 2 semiaxe ale sale
class Ellipse : public IdealFigure
{
private:
	//! @brief Semiaxa majora a elipsei
	double m_a;
	//! @brief Semiaxa minora a elipsei
	double m_b;
protected:

public:
	Ellipse(Point origin = Point(0, 0), double a_axis = 0.0, double b_axis = 0.0) : IdealFigure(origin), m_a(a_axis), m_b(b_axis) {}
	Ellipse(double x_origin = 0.0, double y_origin = 0.0, double a_axis = 0.0, double b_axis = 0.0) : IdealFigure(x_origin, y_origin), m_a(a_axis), m_b(b_axis) {}
	Ellipse(tinyxml2::XMLElement * xmlElem);
	~Ellipse() {}
	//! @brief Aria elipsei 
	double area();

	//! @brief Perimetrul elipsei cu aproximare Ramanujan
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

};