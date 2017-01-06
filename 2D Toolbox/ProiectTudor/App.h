#pragma once

//Implementam modelul Singleton pentru clasa App

class App
{
public:
	//TODO Adaugare date
	//static tip_date data
	

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
protected:

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