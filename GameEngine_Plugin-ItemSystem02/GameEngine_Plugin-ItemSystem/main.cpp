//	Library includes
#include <conio.h>


//	Local includes
#include "debugdisplay.h"
#include "itemcontainer.h"
#include "item.h"


//	Global variables


int main()
{
	//	Container size set in constructor
	C_ItemContainer Container = C_ItemContainer(20, 20);

	Print("Item Container created at size 20 * 20.");
	_getch();
	//	Item size and ID set in constructor
	C_Item Item = C_Item(2, 2, 1);
	Print("Item 2 * 2, ID: 1");
	C_Item Item0 = C_Item(2, 2, 2);
	Print("Item 2 * 2, ID: 2");
	C_Item Item1 = C_Item(2, 4, 3);
	Print("Item 2 * 4, ID: 3");
	C_Item Item2 = C_Item(2, 2, 4);
	Print("Item 2 * 2, ID: 4");
	C_Item Item3 = C_Item(1, 3, 5);
	Print("Item 1 * 3, ID: 5");
	Print("Item One through Five created");
	_getch();

	//	Item ptr sent with position to place item in container
	Container.AddItem(&Item, 2, 2);
	Print("Adding Item of ID: 1, At Position: (2, 2)");
	Print(Container.GetInventory());
	_getch();
	Container.AddItem(&Item0, 2, 2);
	Print("Adding Item of ID: 2, At Position: (2, 2)");
	Print(Container.GetInventory());
	_getch();
	Container.AddItem(&Item1, 7, 1);
	Print("Adding Item of ID: 3, At Position: (7, 1)");
	Print(Container.GetInventory());
	_getch();
	Container.AddItem(&Item2, 0, 0);
	Print("Adding Item of ID: 4, At Position: (0, 0)");
	Print(Container.GetInventory());
	_getch();
	Container.AddItem(&Item3, 5, 5);
	Print("Adding Item of ID: 5, At Position: (5, 5)");
	Print(Container.GetInventory());
	_getch();

	//	Print list of items in container
	Print(Container.GetItemList());


	_getch();
	return 0;
}

