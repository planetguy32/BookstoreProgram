#ifndef module_checkout_include_guard_kjqiuhvqiwugasdkncqiwufbhqeviub
#define module_checkout_include_guard_kjqiuhvqiwugasdkncqiwufbhqeviub
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
	virtual bool doInteraction();
};

#endif