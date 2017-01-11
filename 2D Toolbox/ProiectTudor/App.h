#pragma once
#include "List.h"
#include "Figure.h"
#include "Menu.h"

//Implementam modelul Singleton pentru clasa App

//! @brief Clasa prin intermediul careia se lanseaza in executie aplicatia
/*! Clasa implementeaza modelul singleton si furnizeaza metode statice pentru toate functionalitatile aplicatiei
*/
class App
{
public:	

	//! Returneaza instanta clasei App

	/*! @brief Pseudo-constructor
	* Functia are rol de "pseudo constructor". Daca nu exista nici o instanta a acesteia
	* Creaza o noua instanta si returneaza o referinta la aceasta si o salveaza in m_singleApp
	* Daca exista o instanta va returna m_singleApp
	*/
	static App * getInstance()
	{
		if (!m_isInstantiated)
		{
			App::m_singleApp = new App();
			App::m_isInstantiated = true;
		}
		return App::m_singleApp;
	}
	
	//! Destructor
	~App()
	{
		App::m_isInstantiated = false;
	}
public:

	//! Lista de pointeri Figura - Aici se vor stoca datele pe care le manipuleaza aplicatia
	static List<Figure *> data;


	//Toate operatiile vor fi definite ca functii virtuale protejate
	//Clasele pentru meniu vor fi derivate din App si vor face apel la functiile acestea
	// 1. Citire Date
	//-- OK    - Din fisier XML 
	//    - Din fisier txt (doar DataSet)
	// 2. Scriere Date
	//-- OK   - In fisier XML
	//    - In fisier TXT sub forma de vectori scilab
	// 3. Prelucrare date
	//-- OK    - Afisare lista
	//    - Arie totala
	//    - Perimetru total
	//    - Rasterizare
	//    - Idealizare
	//TODO Implementare metode

	//! @brief Icarca date dintr-un fisier XML
	//! @param pXmlName - Numele fisierului
	static void loadXmlData(const char * pXmlName);
	
	//! @brief Incarca date dintr-un fisier in plain-text
	//! Datele vor fi adaugate ca un singur obiect de tip PointSet
	static void loadVertexData(const char * pTxtName);


	//! @brief Exporta datele aplicatiei in format XML
	static void exportXmlData(const char * pXmlName);

	//! @brief Exporta datele aplicatiei intr-un format pentru SciLab. 
	//! In urma executarii scriptului produs se pot vizualiza figurile existente
	static void exportSciData(const char * pTxtName);

	//! @brief Afiseaza la consola datele din aplicatie
	static void printFiguresData();

	//! @brief Calculeaza suma totala a ariilor figurilor
	//! @note PointSet-ul are arie 0
	static double calculateTotalArea();

	//! @brief Calculeaza suma perimetrelor tuturor figurilor
	//! @note Point-set-ul are perimetru 0
	static double calculateTotalPerimeter();

	//! @brief Adauga o figura data ca parametru la lista datelor aplicatiei
	//! @param fig - Un pointer la o figura
	static void addFigure(Figure * fig);

	//static void convertToPloygon();

private:
	//! Reprezinta o instanta a clasei App sau NULL daca nu exista nici o instanta
	static App * m_singleApp;

	//! TRUE - Exista o instanta a clasei | FALSE - clasa nu este instantiata
	static bool m_isInstantiated;
	


	App() 
	{
		//constructor privat;
	};
	App(const App &a)
	{
		//constructor de copiere
	}
};

//! @brief Importa un XML in aplicatie
class OperationImportXML : public Operation
{
public:
	OperationImportXML(char * name) : Operation(name) {};
	void ExecuteOperation();
private:
};


//! @brief Importa date dintr-un fisier text in aplicatie
class OperationImportTXT : public Operation
{
public:
	OperationImportTXT(char * name) : Operation(name) {};
	void ExecuteOperation();
private:
};

//! @brief Exporta datele aplicatiei in format XML
class OperationExportXML : public Operation
{
public:
	OperationExportXML(char * name) : Operation(name) {};
	void ExecuteOperation();
private:
};

//! @brief Exporta datele aplicatiei sub forma de script SciLab care poate fi vizualizat
class OperationExportSCI : public Operation
{
public:
	OperationExportSCI(char * name) : Operation(name) {}
	void ExecuteOperation();
private:

};

//! @brief Afiseaza informatii despre datele din aplicatie la consola
class OperationDisplayFigures : public Operation
{
public:
	OperationDisplayFigures(char * name) : Operation(name) {}
	void ExecuteOperation();
private:
};

//! @brief Calculeaza suma ariilor
class OperationCalculateArea : public Operation
{
public:
	OperationCalculateArea(char * name) : Operation(name) {};
	void ExecuteOperation();
private:
};

//! @brief Calculeaza suma perimetrelor
class OperationCalculatePerimeter : public Operation
{
public:
	OperationCalculatePerimeter(char * name) : Operation(name) {}
	void ExecuteOperation();
private:
};

//! @brief Adauga un obiect de tip Cerc la lista de date
class OperationAddCircle : public Operation
{
public:
	OperationAddCircle(char * name) : Operation(name) {}
	void ExecuteOperation();
};


//! @brief Adauga un poligon regulat
//! Poligonul este dat prin numarul de laturi, lungimea laturii si origine
class OperationAddNgon : public Operation
{
public:
	OperationAddNgon(char * name) :Operation(name) {}
	void ExecuteOperation();
private:
};