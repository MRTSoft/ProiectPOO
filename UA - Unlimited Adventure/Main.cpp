#include <iostream>
#include "GameOperations.h"

int main()
{
	Menu * menu = new Menu("UA");

	menu->Execute();
	delete menu;
	return 0;
}
