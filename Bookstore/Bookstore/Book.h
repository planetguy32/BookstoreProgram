#ifndef BOOK_HEADER_ASDFAEFBWRTxvcuqrgkqgBQ_Ewfbwethbw
#define BOOK_HEADER_ASDFAEFBWRTxvcuqrgkqgBQ_Ewfbwethbw

#include <string>
#include <iostream>

class Book {
private:
	long long int ISBN;
	std::string title;
	std::string author;
	std::string publisher;
	std::string date;
	int qty;
	double wholesale;
	double retail;
public:
	Book();
	~Book();
	void setISBN(long long int i);
	void setTitle(std::string t);
	void setAuthor(std::string a);
	void setPub(std::string p);
	void setQty(int q);
	void setWhole(double w);
	void setRetail(double r);
	void setDate(std::string date);

	long long int getISBN();
	std::string getTitle();
	std::string getAuthor();
	std::string getPub();
	int getQty();
	double getWhole();
	double getRetail();
	std::string getDate();

	void print();

	friend bool operator> (Book &cP1, Book &cP2);
	friend bool operator< (Book &cP1, Book &cP2);
	friend bool operator>= (Book &cP1, Book &cP2);
	friend bool operator<= (Book &cP1, Book &cP2);
	friend bool operator== (Book &cP1, Book &cP2);
	friend bool operator!= (Book &cP1, Book &cP2);
	friend std::ostream& operator<< (std::ostream& cP1, Book &cP2);

};

#endif