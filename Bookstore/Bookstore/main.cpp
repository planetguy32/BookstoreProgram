#include <iostream>
#include "Module.h"
#include "ModuleCheckout.h"
#include "ModuleInventory.h"
#include "ModuleReport.h"

using namespace std;

int main()
{
	Module * modules[3]; 

	ModuleInventory *inventory=new ModuleInventory;
	modules[0] = new ModuleCheckout(inventory);
	modules[1] = inventory;
	modules[2] = new ModuleReport(inventory);

	bool go = true;

	while (go){
		cout << "Bookstore program" << endl;
		cout << "Select a mode:" << endl;
		cout << "    1. Checkout" << endl;
		cout << "    2. Inventory" << endl;
		cout << "    3. Reports" << endl;
		cout << "    4. Exit" << endl;
		cout << endl;
		cout << ":";
		int choice=-1;
		while (!(cin >> choice) || choice > 4 || choice < 0){
			cout << "Invalid choice - only 1-4 are allowed" << endl;
		}
		if (choice == 4)
			go = false;
		else
			modules[choice-1]->doInteraction();
	}
	cout << "Exiting" << endl;
	delete modules[0];
	modules[0] = 0;
	delete modules[1];
	modules[1] = 0;
	delete modules[2];
	modules[2] = 0;

}
