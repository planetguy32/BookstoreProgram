#pragma once
#include "Module.h"
class ModuleCheckout :
	public Module
{
public:
	ModuleCheckout();
	~ModuleCheckout();
	bool doInteraction();
};

