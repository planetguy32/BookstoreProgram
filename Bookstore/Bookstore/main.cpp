#include <iostream>
#include "Module.h"
#include "ModuleCheckout.h"
#include "ModuleInventory.h"
#include "ModuleReport.h"
#include "SystemPrograms.h"


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
		cout << "===Main Menu===" << endl;
		cout << "Select a mode:" << endl;
		cout << "    1. Checkout" << endl;
		cout << "    2. Inventory" << endl;
		cout << "    3. Reports" << endl;
		cout << "    4. Exit" << endl;
		cout << endl;
		cout << ":";
		string strChoice;
		int choice=-1;
		getline(cin, strChoice);
		try{
			choice = stoi(strChoice);
		}
		catch (std::invalid_argument)
		{
			choice = -1;
		}
		
		while ( !(choice <=4 && choice >= 1)){

			cout << "Invalid choice - only 1-4 are allowed" << endl;
			getline(cin, strChoice);
			try{
				choice = stoi(strChoice);
			}
			catch (std::invalid_argument)
			{
				choice = -1;
			}
		}
		if (choice == 4)
			go = false;
		else
		{
			system_clear();
			modules[choice-1]->doInteraction();
			system_pause();
			system_clear();
		}
	}
	cout << "Saving" << endl;
	delete modules[0];
	modules[0] = 0;
	cout << "Cleaning up" << endl;
	delete modules[1];
	modules[1] = 0;
	delete modules[2];
	modules[2] = 0;
	cout << "Done" << endl;
	
}
