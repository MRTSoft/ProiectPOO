#include <string.h>

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

void App::printFiguresData()
{
	List<Figure *>::listElem * p = App::data.getHead();
	while (p != nullptr)
	{
		p->data->print(std::cout);
		p = p->next;
	}
}
