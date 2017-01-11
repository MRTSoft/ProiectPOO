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

/*
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
*/

int main()
{
	//App* a = App::getInstance();
	using namespace tinyxml2;
	using namespace std;

	//ACTUAL APP
	Menu * menu = new Menu("2D Toolbox");
	Menu * importSubmenu = new Menu("Importa date");
	Menu * exportSubmenu = new Menu("Exporta date");
	Menu * procesSubmenu = new Menu("Procesare date");
	Menu * procAddSubmenu = new Menu("Adaugare Figuri");
	
	menu->AddItem(importSubmenu);
	importSubmenu->AddItem(new OperationImportXML("Din format XML"));


	menu->AddItem(exportSubmenu);
	exportSubmenu->AddItem(new OperationExportXML("In format XML"));
	
	menu->AddItem(procesSubmenu);
	procesSubmenu->AddItem(new OperationCalculateArea("Calcul ARIE"));
	procesSubmenu->AddItem(new OperationCalculatePerimeter("Calcul PERIMETRU"));
	procesSubmenu->AddItem(new OperationDisplayFigures("Afisare date"));
	procesSubmenu->AddItem(procAddSubmenu);
	procAddSubmenu->AddItem(new OperationAddCircle("Cerc"));
	procAddSubmenu->AddItem(new OperationAddNgon("Poligon regulat"));


	//procesSubmenu->AddItem(new OperationAddCircle("Cerc"));
	menu->Execute();

	return 0;
}