#pragma once
#include <ostream>
#include "tinyxml2.h"


//! @brief Reprezinta un punct cu coordonate reale in plan
//! @note Sistemul de referinta nu este orientat deci nu conteaza pozitia axelor dar acestea trebuie sa fie perpendiculare
class Point
{
public:
	typedef double pointType;

	//! Coordonata Y a punctului
	pointType y;
	//! Coordonata X a punctului
	pointType x;



	Point();
	Point(pointType p_x, pointType p_y);
	Point(tinyxml2::XMLElement * elem);
	//! Euclidean distence between 2 points

	/*! @brief Distanta Euclideana intre punctul curent si un punct dat ca parametru
	* Calculeaza sqrt((x_b - x_a)^2 + (y_b - y_a)^2)
	*/
	double distanceTo(const Point &p);

	//! @brief Afiseaza informatii despre obiect la un stream
	void print(std::ostream & g);

	//! @brief Creeaza un nod XML care contine informatii despre obiectul curent
	//! Nodul XML nu este atasat documentului xml
	//! @param xmlDoc - Documentul caruia apartine nodul generat
	tinyxml2::XMLNode * serialize(tinyxml2::XMLDocument & xmlDoc);

protected:

private:
};

//Interfata - Clasa de baza
//! @brief Clasa de baza pentru date. Din aceasta deriva toate figurile
//! Clasa este abstracta
class Figure
{
public:
	virtual ~Figure() {};

	virtual void print(std::ostream & g) = 0;
	virtual double area() = 0;
	virtual double perimeter() = 0;
	virtual tinyxml2::XMLNode * serialize(tinyxml2::XMLDocument &xmlDoc) = 0;
protected:

private:

};