#pragma once
#include "List.h"
#include "Figure.h"

//Implementam modelul Singleton pentru clasa App

class App
{
public:	

	//! Returneaza instanta clasei App

	/*!
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
//protected: // PRODUCTION
public: //DEBUG ONLY!!!!
	//TODO MOdificat aceasta sectiune ca protected

	//static tip_date data
	//Lista de pointeri Figura
	static List<Figure *> data;


	//Toate operatiile vor fi definite ca functii virtuale protejate
	//Clasele pentru meniu vor fi derivate din App si vor face apel la functiile acestea
	// 1. Citire Date
	//    - Din fisier XML
	//    - Din fisier txt (doar DataSet)
	// 2. Scriere Date
	//    - In fisier XML
	//    - In fisier TXT sub forma de vectori scilab
	// 3. Prelucrare date
	//    - Afisare lista
	//    - Arie totala
	//    - Perimetru total
	//    - Rasterizare
	//    - Idealizare
	//TODO Implementare metode
	static void loadXmlData(const char * pXmlName);
	//static void loadVertexData(char * pTxtName);

	//static void exportXmlData(char * pXmlName);
	//static void exportTxtData(char * pTxtName);

	static void printFiguresData();
	//static void calculateTotalArea();
	//static void calculateTotalPerimeter();

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