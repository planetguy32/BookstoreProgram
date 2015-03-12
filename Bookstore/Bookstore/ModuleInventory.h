#pragma once
#include "Module.h"
#include "Book.h"
#include <string>
#include <vector>


/*
ModuelInventory Class



	Book Class (SUBCLASS?)
		-declare variables: ISBN, title, author, publisher, addDate, qty, wholesale, retail
		-constructor
		-destructor
		-set functions
		-get functions
	Set Functions
		-initialize variables to get data
	Get Functions
		-ofstream open file
		-pull from BookList file into appropriate variables
		-ofstream close file
*/
#pragma once
#include "Module.h"
#include <string>
#include <vector>

class ModuleInventory :
	public Module
{
private:
	std::vector<Book *> books;
	std::string * split(std::istream& in, char splitChar);
	Book * findBook(long long int isbn, int start, int end);
	Book * parseBook(std::string * inputArrayOf8);
public:
	ModuleInventory();
	~ModuleInventory();
	bool doInteraction();
	Book * getBook(long long int isbn);
};
