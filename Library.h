#pragma once
#include <iostream>
#include <string>

struct node
{
	std::string author_name;
	std::string book_title;
	int copies;
	node* next = nullptr;
};

struct branch
{
	std::string branch_name;
	node* firstBook = nullptr;
};

class Library
{
public:
	Library();
	void create();
	node* add(std::string, std::string, int, branch*);
	void printBranch(std::string);
	void checkoutBook();
	void deleteBook(branch*, std::string, std::string);
	void returnBook(std::string, std::string, std::string);
	void getCopies(std::string, std::string, std::string);
private:
	static branch bArray[100];
	static int free;
};