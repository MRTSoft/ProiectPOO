#include <iostream>
#include <conio.h>
#include <string.h>
#include "Globals.h"
#include"Menu.h"
using namespace std;

/****** Membri clasa MenuItem ******/
MenuItem::MenuItem(char *name)
{
	this->m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	this->m_parent = nullptr;
}

//afiseaza titlul mai putin caracterele de sfarsit, 
//pentru a putea fi utilizata in afisarea propriului titlu cat si a fiilor.
void MenuItem::IncompleteTitleDisplay(void)
{
	if (m_parent != nullptr)
	{
		m_parent->IncompleteTitleDisplay();
		std::cout << " -> " << m_name;
	}
	else
	{
		std::cout << m_name;
	}
}

void MenuItem::DisplayTitle(void)
{
	IncompleteTitleDisplay();
	std::cout << ":" << endl << endl;
}

char *MenuItem::GetName(void)
{
	return this->m_name;
}

MenuItem::~MenuItem(void)
{
	std::cout << "stergere element: " << m_name << endl;
	delete[] m_name;
}

/****** Membri clasa Operation ******/

Operation::Operation(char *name) : MenuItem(name)
{
}

void Operation::Execute()
{
	ClearScreen();
	this->DisplayTitle();
	this->ExecuteOperation();
}

/****** Membri clasa Menu ******/

Menu::Menu(char *name) : MenuItem(name)
{
	this->m_items = new MenuItem*[m_nMaxItems];
	this->m_nItems = 0;
}

//va dealoca memoria pentru toate elementele, eventual recursiv.
Menu::~Menu()
{
	for (int i = 0; i<m_nItems; i++)
	{
		delete m_items[i];
	}
	delete[] m_items;
}

void Menu::AddItem(MenuItem *item)
{
	m_nItems++;
	m_items[m_nItems - 1] = item;
	item->m_parent = this;
}

void Menu::Display(void)
{
	for (int i = 0; i < this->m_nItems; i++)
	{
		cout << "\t" << i + 1 << " - " << m_items[i]->GetName();
		cout << endl << endl;
	}
	cout << "\t" << "ESC sau 0 - Iesire" << endl << endl;
}

//returneaza indicele elementului activat, sau -1 pentru iesire
int Menu::ReadCommand(void)
{
	while (1)
	{
		char ch;

		cout << "Introduceti comanda:";
		ch = _getch();
		cout << endl;
		if (ch > '0' && (ch - '0') <= this->m_nItems)
		{
			//element meniu
			int comanda = ch - '1';// pt '1' va fi elementul 0

			return comanda;
		}
		else if (ch == '0' || ch == 0x1B)
		{
			//0 sau ESC - iesire din meniu
			return -1;
		}
		else
		{
			//tasta invalida
			std::cout << "Tasta invalida: " << ch
				<< " Tastele valide sunt '0' - '" << m_nItems << "'"
				<< endl << endl;
		}
	}
}

void Menu::Execute(void)
{
	for (;;)
	{
		int command;

		ClearScreen();
		DisplayTitle();
		Display();
		command = ReadCommand();
		if (command >= 0 && command < m_nItems)
		{
			m_items[command]->Execute();
		}
		else
		{
			//probabil iesirea - -1
			return;
		}
	}
}
