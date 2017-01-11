#include <string.h>
#include <fstream>

#include "App.h"
#include "tinyxml2.h"
#include "ConvexPolygon.h"
#include "Circle.h"
#include "Ellipse.h"


List<Figure *> App::data;

void App::loadXmlData(const char * pXmlName)
{
	tinyxml2::XMLDocument xmlDoc;
	tinyxml2::XMLError xmlErr;
	xmlErr = xmlDoc.LoadFile(pXmlName);

	if (xmlErr == tinyxml2::XMLError::XML_SUCCESS)
	{
		xmlDoc.Print();
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
			if (strcmp(elemIt->Name(), "PointSet") == 0)
			{
				Figure * ps = new PointSet(elemIt);
				App::data.insert(ps);
			}

			if (strcmp(elemIt->Name(), "ConvexPolygon") == 0)
			{
				Figure * cp = new ConvexPolygon(elemIt);
				App::data.insert(cp);
			}
			if (strcmp(elemIt->Name(), "Circle") == 0)
			{
				Figure * crc = new Circle(elemIt);
				App::data.insert(crc);
			}
			if (strcmp(elemIt->Name(), "Ellipse") == 0)
			{
				Figure * elp = new Ellipse(elemIt);
				App::data.insert(elp);
			}
			elemIt = elemIt->NextSiblingElement();
		}
	}
	else
	{
		//TODO Error handling code here
	}

}

void App::exportXmlData(char * pXmlName)
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
