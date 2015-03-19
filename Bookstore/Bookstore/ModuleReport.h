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

	void dumpBookList();
		
	template<class T>
	void dumpBookList(T(Book::* f)());

	template<class T>
	void listBy(T(Book::* f)());

	template<class T>
	void sortBy(T(Book::* f)());

	template<class T>
	void accumulate(T(Book::* f)());

};
