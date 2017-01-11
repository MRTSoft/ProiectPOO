#pragma once
#include <ostream>
#include "tinyxml2.h"


class Point
{
public:
	typedef double pointType;
	pointType y;
	pointType x;



	Point();
	Point(pointType p_x, pointType p_y);
	Point(tinyxml2::XMLElement * elem);
	//! Euclidean distence between 2 points

	/*!
	* Evaluates sqrt((x_b - x_a)^2 + (y_b - y_a)^2)
	*/
	void print(std::ostream & g);
	double distanceTo(const Point &p);
	tinyxml2::XMLNode * serialize(tinyxml2::XMLDocument & xmlDoc);

protected:

private:
};

//Interfata - Clasa de baza
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