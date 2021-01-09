#include "Library.h"
#include <iostream>

using namespace std;

void makeBranch(Library);
void checkout(Library);
void returnB(Library);
void getNumCopies(Library);
void printBooks(Library);

int main()
{
	int request = 1;
	Library l;

	while (request > 0 && request <= 5)
	{
		cout << "What do you wish to do: " << endl;
		cout << "1) Create a branch and add books." << endl;
		cout << "2) Checkout a book." << endl;
		cout << "3) Return a book." << endl;
		cout << "4) Find copies of a book in a branch." << endl;
		cout << "5) Print all books in one branch." <<  endl;
		cout << "6) Exit." << endl;
		cin >> request;

		switch (request)
		{
		case 1:
			makeBranch(l);
			break;
		case 2:
			checkout(l);
			break;
		case 3:
			returnB(l);
			break;
		case 4:
			getNumCopies(l);
			break;
		case 5:
			printBooks(l);
			break;
		}
	}
}

void makeBranch(Library lib)
{
	lib.create();
}

void checkout(Library lib)
{
	lib.checkoutBook();
}

void printBooks(Library lib)
{
	string s;
	cout <<  endl << "Enter the name of the branch: " << endl;
	cin.ignore();
	getline(cin, s);
	cout << endl;
	lib.printBranch(s);
}

void returnB(Library lib)
{
	string branch; string author; string title;
	cout << endl << "Enter the name of the branch: " << endl;
	cin.ignore();
	getline(cin, branch);
	cout << "Enter the name of the author: " << endl;
	getline(cin, author);
	cout << "Enter the name of the book: " << endl;
	getline(cin, title);
	lib.returnBook(branch, author, title);
}

void getNumCopies(Library lib)
{
	string branch; string author; string title;
	cout << endl << "Enter the name of the branch: " << endl;
	cin.ignore();
	getline(cin, branch);
	cout << "Enter the name of the author: " << endl;
	getline(cin, author);
	cout << "Enter the name of the book: " << endl;
	getline(cin, title);
	lib.getCopies(branch, author, title);
}