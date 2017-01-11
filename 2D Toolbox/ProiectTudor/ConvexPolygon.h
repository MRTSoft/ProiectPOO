#pragma once
#include "PointSet.h"
#include <iostream>
//! @brief Implementeaza un poligon Convex
//! @note Oridinea in care sunt date punctele poligonului trebuie sa urmeze chenarul poligonului
//! @note Pentru poligoane care nu sunt convexe Aria poate oferi valori neasteptate
class ConvexPolygon : public PointSet
{
public:
	ConvexPolygon(List<Point> lst = List<Point>(), unsigned lst_count = 0);
	ConvexPolygon(tinyxml2::XMLElement * xmlElem);
	//! @brief Aria este calculata prin triangularizarea poligonului
	double area();
	//! @brief Perimetru
	double perimeter();

	//! @briefAfiseaza informatii despre obiect intr-un stream
	void print(std::ostream & g);
	//! @brief Creeaza un nod XML care contine informatii despre obiectul curent
	//! Nodul XML nu este atasat documentului xml
	//! @param xmlDoc - Documentul caruia apartine nodul generat
	virtual tinyxml2::XMLNode *	serialize(tinyxml2::XMLDocument & xmlDoc);

	//! @brief Scrie in stream-ul g o reprezentare a poligonului
	//! Sunt generati 2 vectori x si y care contin coordonatele punctelor polinomului
	//! Exista si o functie specifica scilab care face resize la zona de desenare
	void sci_print_points(std::ostream &g);

	
protected:

private:

};