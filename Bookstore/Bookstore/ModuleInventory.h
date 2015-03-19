#pragma once
#include "Module.h"
#include "Book.h"
#include <string>
#include <vector>
#include <list>


/*
ModuelInventory Class
*/

class ModuleInventory :
	public Module
{
private:
	std::string * split(std::istream& in, char splitChar);

	template<class T>
	//find book whose member function f returns T and which is between start and end.
	Book * findBook(T searchTerm, T(Book::* f)(), int start, int end);
	Book * parseBook(std::string * inputArrayOf8);
public:
	std::vector<Book *> books;
	
	ModuleInventory();
	~ModuleInventory();
	bool doInteraction();

	Book * Action(Book *);

	//find book whose member function f returns T
	template<class T>
	Book * getBook(T searchTerm, T(Book::* f)());

	//find book with the given ISBN
	Book * getBook(long long int isbn);

	//find the position of the book whose member function f returns T
	template<class T>
	int getBookIndex(T searchTerm, T(Book::* f)(), int start, int end);

};
