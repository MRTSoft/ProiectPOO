#pragma once


class Point
{
public:
	typedef double pointType;
	pointType y;
	pointType x;



	Point();
	Point(pointType p_x, pointType p_y);
	//! Euclidean distence between 2 points

	/*!
	* Evaluates sqrt((x_b - x_a)^2 + (y_b - y_a)^2)
	*/
	double distanceTo(const Point &p);

protected:

private:
};

//Interfata - Clasa de baza
class Figure
{
public:
	virtual ~Figure() {};

	virtual double area() = 0;
	virtual double perimeter() = 0;
protected:

private:

};