#pragma once
#include "Module.h"
#include "ModuleInventory.h"
#include <vector>

class ModuleReport :
	public Module
{
private:
	ModuleInventory *inventory;

public:
	
	ModuleReport(ModuleInventory *inventory);
	~ModuleReport();

	bool doInteraction(); 

	void listInv();
	void wholeValue();
	void retailValue();
	void listByQty();
	void listByCost();
	void listByAge();


};
