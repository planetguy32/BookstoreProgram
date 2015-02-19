#pragma once
#include "Module.h"
class ModuleInventory :
	public Module
{
public:
	ModuleInventory();
	~ModuleInventory();

	bool doInteraction();
};

