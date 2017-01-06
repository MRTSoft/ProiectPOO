#pragma once

#pragma once

//Un element de meniu in general. Poate fi atat o operatie cat si un meniu.
class MenuItem
{
private:
	char *m_name;
	MenuItem *m_parent;

protected:
	MenuItem(char *name);
	virtual ~MenuItem(void);
	void IncompleteTitleDisplay(void);//afiseaza titlul mai putin caracterele 
									  //de sfarsit, pentru a putea fi utilizata in afisarea propriului titlu
									  //cat si a fiilor.
	void DisplayTitle(void); // va apela afisareIncompletaTitlu() + va tipari 
							 //caracterele de sfarsit	

public:
	char *GetName(void);

	//va contine logica executata la activarea acestui element
	virtual void Execute(void) = 0;

	//este necesar pentru a putea seta parintele din clasa Meniu, si doar 
	//de acolo.
	friend class Menu;
};

//un element de Menu care efectueaza o operatie. 
//Reprezinta o frunza in arborele meniului
class Operation : public MenuItem
{
protected:
	Operation(char *name);

	//operatia specifica acestui element
	virtual void ExecuteOperation(void) = 0;

public:
	//intreaga logica a elementului - afisare titlu + operatie
	void Execute(void);
};

//Reprezinta un element meniu care la randul sau este meniu. 
//Poate fi atat meniul principal cat si un submeniu
class Menu : public MenuItem
{
private:
	static const int m_nMaxItems = 9;
	int m_nItems;

	//Meniul este stapan peste memoria fiilor sai.
	//Astfel, la dealocare va dealoca si memoria fiilor.
	MenuItem **m_items;

	//afiseaza meniul la consola
	void Display(void);

	//asteapta apasarea unei taste, si activeaza elementul respectiv 
	//de meniu returneaza indicele fiului, sau -1 pentru iesire
	int ReadCommand(void);

public:
	Menu(char *name);

	//va dealoca fii sai, eventual recursiv.
	~Menu();

	void AddItem(MenuItem *item);
	void Execute(void);
};
