#include <iostream>
#include "Globals.h"
#include "GameOperations.h"
using namespace std;

/* SAMPLE CODE FOR MENU LIB

//****** Membri clasa OperatieAdunare ******
AdditionOperation::AdditionOperation(char *name) : Operation(name)
{
}

void AdditionOperation::ExecuteOperation(void)
{
	int a, b;
	cout << "Introduceti 2 numere:";
	cin >> a >> b;
	cout << "suma = " << a + b << endl;
	Pause();
}

//****** Membri clasa OperatieScadere ******
SubstractionOperation::SubstractionOperation(char *name) : Operation(name)
{
}

void SubstractionOperation::ExecuteOperation(void)
{
	int a, b;
	cout << "Introduceti 2 numere:";
	cin >> a >> b;
	cout << "diferenta = " << a - b << endl;
	Pause();
}

///******  Membri clasa ElementDespre ******
AboutItem::AboutItem(char *name) : Operation(name)
{
}

void AboutItem::ExecuteOperation(void)
{
	cout << "Demonstratie meniuri la consola folosind polimorfismul." << endl;
	cout << "In orice moment este posibila adaugarea unui nou meniu"
		<< " cu propriile elemente."
		<< " Singurele modificari din program ar fi"
		<< " scrierea noilor clase pentru elemente,"
		<< " si adaugarea elementelor la meniu in functia main."
		<< endl;
	Pause();
}

// */
