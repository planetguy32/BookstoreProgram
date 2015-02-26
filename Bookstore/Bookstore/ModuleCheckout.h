#pragma once
#include "Module.h"
class ModuleCheckout :
	public Module
{
private:
	ModuleInventory * inventory;
public:
	ModuleCheckout(ModuleInventory * inv)
	{
		inventory=inv;
	}
	~ModuleCheckout();
	bool doInteraction();
};

