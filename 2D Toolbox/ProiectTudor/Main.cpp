#include <iostream>
#include <fstream>

#include "App.h"
#include "List.h"
#include "Ellipse.h"
#include "Circle.h"
#include "ConvexPolygon.h"

int main()
{
	//App* a = App::getInstance();
	Circle c1(Point(0, 0), 1.0);
	ConvexPolygon c20 = c1.rasterize(500);
	std::cout <<   "Circle      Area: " << c1.area();
	std::cout << "\nCircle Poly Area: " << c20.area();

	std::cout << "\nCircle      Perim: " << c1.perimeter();
	std::cout << "\nCircle Poly Perim: " << c20.perimeter();
	Ellipse e1(Point(0.0, 0.0), 2, 1);
	
	ConvexPolygon e20 = e1.rasterize(200);
	std::cout << "\n\nEllipse      Area: " << e1.area();
	std::cout << "\nEllipse Poly Area: " << e20.area();

	std::cout << "\nEllipse      Perim: " << e1.perimeter();
	std::cout << "\nEllipse Poly Perim: " << e20.perimeter() << std::endl;
	
	std::ofstream g("output.sci");
	e1.rasterize(5).dbg_print_points(g);
	e1.rasterize(13).dbg_print_points(g);
	e1.rasterize(25).dbg_print_points(g);
	//e20.dbg_print_points(g);
	g.close();
	return 0;
}