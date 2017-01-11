#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>

#include "App.h"
#include "List.h"
#include "Ellipse.h"
#include "Circle.h"
#include "ConvexPolygon.h"
#include "tinyxml2.h"


void RecursivePrint(tinyxml2::XMLElement * node)
{
	if (node != 0)
	{
		std::cout << node->Value();
		bool hasAtributes = (node->FirstAttribute() != 0);
		std::cout << " -> ";
		if (hasAtributes)
			std::cout << node->FirstAttribute()->Value();
		else
			std::cout << "No atributes!";
		std::cout << std::endl;
		tinyxml2::XMLElement * iterator = node->FirstChildElement();
		while (iterator)
		{
			RecursivePrint(iterator);
			iterator = iterator->NextSiblingElement();
		}
	}
}

int main()
{
	//App* a = App::getInstance();
	using namespace tinyxml2;
	using namespace std;

	/*
	Circle myCirc(0, 0, 20.5);
	tinyxml2::XMLDocument xmlDoc;
	XMLNode * pRoot = xmlDoc.NewElement("Root");
	XMLDeclaration * dec = xmlDoc.NewDeclaration();
	xmlDoc.InsertFirstChild(pRoot);
	xmlDoc.InsertFirstChild(dec);
	
	XMLElement * auxPt = xmlDoc.NewElement("Point");
	auxPt->SetAttribute("x", 1.0f);
	auxPt->SetAttribute("y", 2.0f);
	XMLNode * curPos = pRoot->InsertFirstChild(auxPt);

	auxPt = xmlDoc.NewElement("Point");

	auxPt->SetAttribute("x", 3.0f);
	auxPt->SetAttribute("y", 4.0f);
	curPos = pRoot->InsertAfterChild(curPos, auxPt);
	XMLNode * xmlCirc = myCirc.serialize(xmlDoc);
	curPos = pRoot->InsertAfterChild(curPos, xmlCirc);

	//std::ifstream * fp = new std::ifstream("first.xml");
	FILE * fp = new FILE;
	fopen_s(&fp, "first.xml", "w");
	xmlDoc.SaveFile(fp);
	fclose(fp);

	

	//xmlDoc.LoadFile("first.xml");
	xmlDoc.Print();
	*/
	XMLDocument xmlDoc;
	//xmlDoc.LoadFile("first.xml");
	XMLNode * pRoot = xmlDoc.NewElement("Root");
	XMLDeclaration * dec = xmlDoc.NewDeclaration();
	xmlDoc.InsertFirstChild(pRoot);
	xmlDoc.InsertFirstChild(dec);

	//XMLElement * docRoot = xmlDoc.RootElement();
	//XMLElement * xmlFigure = docRoot->FirstChildElement();
	//RecursivePrint(docRoot);
	List<Point> lp;
	lp.insert(Point(1, 1)); lp.insert(Point(1, 2)); lp.insert(Point(2, 2)); lp.insert(Point(2, 1));
	ConvexPolygon cp(lp,4);
	Ellipse el(Point(0, 0), 2, 1);
	lp.removeHead();
	PointSet ps(lp, 3);
	XMLNode * cpXML = cp.serialize(xmlDoc);
	pRoot->InsertFirstChild(cpXML);
	pRoot->InsertFirstChild(el.serialize(xmlDoc));
	pRoot->InsertFirstChild(ps.serialize(xmlDoc));
	pRoot->InsertFirstChild(Circle(0, 0, 10).serialize(xmlDoc));
	pRoot->InsertFirstChild(Point(5, 3.57).serialize(xmlDoc));
	//xmlDoc.Print();
	

	FILE * fp = new FILE;
	fopen_s(&fp, "first.xml", "w");
	xmlDoc.SaveFile(fp);
	fclose(fp);

	App::loadXmlData("first.xml");

	App::printFiguresData();

	return 0;
}