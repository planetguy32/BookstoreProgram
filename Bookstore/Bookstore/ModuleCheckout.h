#pragma once
#include "Module.h"
#include "ModuleInventory.h"

class ModuleCheckout :
	public Module
{
private:
	ModuleInventory *inventory;
public:
	ModuleCheckout(ModuleInventory *inv);
	~ModuleCheckout();
	bool doInteraction();
};

