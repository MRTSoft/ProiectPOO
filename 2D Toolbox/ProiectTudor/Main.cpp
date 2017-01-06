#include <iostream>
#include <fstream>
#include <stdio.h>

#include "App.h"
#include "List.h"
#include "Ellipse.h"
#include "Circle.h"
#include "ConvexPolygon.h"
#include "tinyxml2.h"

int main()
{
	//App* a = App::getInstance();
	using namespace tinyxml2;

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
	return 0;
}