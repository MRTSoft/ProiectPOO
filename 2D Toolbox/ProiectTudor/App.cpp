#include <string.h>
#include <string>
#include <fstream>

#include "App.h"
#include "tinyxml2.h"
#include "ConvexPolygon.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Globals.h"


List<Figure *> App::data;

void App::loadXmlData(const char * pXmlName)
{
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError xmlErr;
	xmlErr = xmlDoc.LoadFile(pXmlName);

	if (xmlErr == tinyxml2::XMLError::XML_SUCCESS)
	{
		tinyxml2::XMLElement * elemIt = xmlDoc.RootElement()->FirstChildElement();
		while (elemIt)
		{
			if (strcmp(elemIt->Name(), "Point") == 0)
			{
				//Point Element - Convert to a Point Set containing all the adiacent points
				List<Point> pl;
				unsigned points_nr = 0;
				//pl.insert(Point(elemIt));
				while (elemIt && strcmp(elemIt->Name(), "Point") == 0)
				{
					pl.insert(Point(elemIt));
					points_nr++;
					elemIt = elemIt->NextSiblingElement();
				}
				//PointSet ps(pl, points_nr);
				Figure * fg = new PointSet(pl, points_nr);
				App::data.insert(fg);
			}
			else if (strcmp(elemIt->Name(), "PointSet") == 0)
			{
				Figure * ps = new PointSet(elemIt);
				App::data.insert(ps);
				elemIt = elemIt->NextSiblingElement();
			}
			else if (strcmp(elemIt->Name(), "ConvexPolygon") == 0)
			{
				Figure * cp = new ConvexPolygon(elemIt);
				App::data.insert(cp);
				elemIt = elemIt->NextSiblingElement();
			}
			else if (strcmp(elemIt->Name(), "Circle") == 0)
			{
				Figure * crc = new Circle(elemIt);
				App::data.insert(crc);
				elemIt = elemIt->NextSiblingElement();
			}
			else if (strcmp(elemIt->Name(), "Ellipse") == 0)
			{
				Figure * elp = new Ellipse(elemIt);
				App::data.insert(elp);
				elemIt = elemIt->NextSiblingElement();
			}
			else
			{
				elemIt = elemIt->NextSiblingElement();
			}
		}
	}
	else
	{
		//TODO Error handling code here
	}

}

//!loads data from a file and converts in to a Point Set
void App::loadVertexData(const char * pTxtName)
{
	std::ifstream f(pTxtName);
	unsigned n = 0;
	List<Point> lst;
	if (f.is_open())
	{
		double x, y;
		while(!f.eof() && f)
		{
			f >> x;
			if (!f.eof())
			{
				f >> y;
				lst.insert(Point(x, y));
				n++;
			}
		}
		f.close();
		Figure * ps = new PointSet(lst, n);
		App::addFigure(ps);
	}
}

void App::exportXmlData(const char * pXmlName)
{
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLElement * pRoot = xmlDoc.NewElement("Root");
	
	xmlDoc.InsertFirstChild(pRoot);
	xmlDoc.InsertFirstChild(xmlDoc.NewDeclaration());

	List<Figure *>::listElem * p = App::data.getHead();
	tinyxml2::XMLNode * xmlElem = 0;
	tinyxml2::XMLNode * iterator = 0;
	if (p != nullptr)
	{
		xmlElem = p->data->serialize(xmlDoc);
		pRoot->InsertFirstChild(xmlElem);
		iterator = xmlElem;
		p = p->next;
	}
	while (p != nullptr)
	{
		xmlElem = p->data->serialize(xmlDoc);
		pRoot->InsertAfterChild(iterator, xmlElem);
		iterator = xmlElem;
		p = p->next;
	}
	
	FILE * fp = new FILE;
	fopen_s(&fp, pXmlName, "w");
	xmlDoc.SaveFile(fp);
	fclose(fp);
}

//! Functie de scris in fisier
/*!
 * @param pTxtName Fisierul in care se scrie

*/
void App::exportSciData(const char * pTxtName)
{
	std::ofstream g(pTxtName);
	if (g.is_open())
	{
		List<Figure *>::listElem * p = App::data.getHead();
		while (p != nullptr)
		{
			ConvexPolygon * res = NULL;
			ConvexPolygon * poly = dynamic_cast<ConvexPolygon*>(p->data);
			if (poly == NULL) //Circle or Ellipse
			{
				Circle * circ = dynamic_cast<Circle *>(p->data);
				if (circ == NULL)//Ellipse?
				{
					Ellipse * ell = dynamic_cast<Ellipse *>(p->data);
					if (ell != NULL)
					{
						res = ell->rasterize();
					}
				}
				else {
					res = circ->rasterize();
				}
			}
			else {
				res = poly;
			}
			if (res != NULL) {
				res->sci_print_points(g);
			}
			p = p->next;
		}// while
		g.close();
	}
}

void App::printFiguresData()
{
	List<Figure *>::listElem * p = App::data.getHead();
	while (p != nullptr)
	{
		p->data->print(std::cout);
		p = p->next;
	}
}

double App::calculateTotalArea()
{
	double tArea = 0;
	List<Figure *>::listElem * p = App::data.getHead();
	while (p != nullptr)
	{
		tArea += p->data->area();
		p = p->next;
	}
	return tArea;
}

double App::calculateTotalPerimeter()
{
	double tPerim = 0;
	List<Figure *>::listElem * p = App::data.getHead();
	while (p != nullptr)
	{
		tPerim += p->data->area();
		p = p->next;
	}
	return tPerim;
}
//! Adauga o figura la lista curenta
void App::addFigure(Figure * fig)
{
	App::data.insert(fig);
}


/* 
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * - - - - - - - - - - - - - - - - -    OPERATII   - - - - - - - - - - - - - - - - - - - - -
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

void OperationImportXML::ExecuteOperation()
{
	std::string xmlName = "";
	std::cout << "Introduceti numele fisierului XML: \n > ";
	std::cin >> xmlName;
	App::loadXmlData(xmlName.c_str());
	std::cout << "Datele au fost importate cu succes!\n";
	Pause();
}

void OperationImportTXT::ExecuteOperation()
{
	std::string fName = "";
	std::cout << "Introduceti numele fisierului TXT: \n > ";
	std::cin >> fName;
	App::loadVertexData(fName.c_str());
	std::cout << "Date importate!";
	Pause();
}

void OperationExportXML::ExecuteOperation()
{
	std::string xmlName = "";
	std::cout << "Introduceti numele fisierului XML: \n > ";
	std::cin >> xmlName;
	App::exportXmlData(xmlName.c_str());
	std::cout << "Datele au fost exportate cu succes!\n";
	Pause();
}

void OperationExportSCI::ExecuteOperation()
{
	std::string fName = "";
	std::cout << "Introduceti numele fisierului SCI (va fi creat): \n > ";
	std::cin >> fName;
	App::exportSciData(fName.c_str());
	std::cout << "Done!";
	Pause();
}

void OperationDisplayFigures::ExecuteOperation()
{
	App::printFiguresData();
	Pause();
}

void OperationCalculateArea::ExecuteOperation()
{
	double area = App::calculateTotalArea();
	std::cout << "Suma ariilor figurilor este: " << area;
	std::cout << "\n";
	Pause();
}

void OperationCalculatePerimeter::ExecuteOperation()
{
	double perim = App::calculateTotalPerimeter();
	std::cout << "Suma perimetrelor figurilor este: " << perim;
	std::cout << "\n";
	Pause();
}

void OperationAddCircle::ExecuteOperation()
{
	double radius = 0;
	Point origin;
	std::cout << "Introduceti diametrul cercului: ";
	std::cin >> radius;
	radius = radius / 2;
	std::cout << "Origine: \n\tx = ";
	std::cin >> origin.x;
	std::cout << "\ty = ";
	std::cin >> origin.y;
	Figure * circle = new Circle(origin, radius);
	App::addFigure(circle);
	std::cout << "Adaugat!";
	Pause();
}

void OperationAddNgon::ExecuteOperation()
{
	double radius = 0;
	Point origin;
	unsigned sides = 4;
	std::cout << "Introduceti numarul de laturi: ";
	std::cin >> sides;
	std::cout << "Introduceti latura poligonului regulat: ";
	std::cin >> radius;
	radius = radius / (2 * sin(PI/sides));
	std::cout << "Origine: \n\tx = ";
	std::cin >> origin.x;
	std::cout << "\ty = ";
	std::cin >> origin.y;
	Figure * circle = new Circle(origin, radius);
	circle = dynamic_cast<Circle *>(circle)->rasterize(sides);
	App::addFigure(circle);

}


