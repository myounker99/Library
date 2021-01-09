#include "Library.h"
#include <string>

using namespace std;

branch Library::bArray[100];
int Library::free = 0;

Library::Library()
{
	
}

void Library::create()
{
	branch newB; int numDifBooks;
	cout << endl << "Enter the name of the branch: " << endl;
	cin.ignore();
	getline(cin, newB.branch_name);

	cout << endl << "How many different books will there be?" << endl;
	cin >> numDifBooks; cout << endl;
	
	string auth; string title; int cop;

	for (int i = 0; i < numDifBooks; i++)
	{
		cout << "Enter the author of book " << i + 1 << ": " << endl;
		cin.ignore();
		getline (cin, auth);

		cout << "Enter the title of book " << i + 1 << ": " << endl;
		getline (cin, title);

		cout << "Enter the number of copies of book " << i + 1 << ": " << endl;
		cin >> cop;

		cout << endl;

		add(auth, title, cop, &newB);
	}
	bArray[free] = newB;
	free++;

}

node* Library::add(string a, string t, int c, branch* b)
{
	node* cPtr;
	node* pPtr;
	node* newNPtr = new node;
	newNPtr->author_name = a;
	newNPtr->book_title = t;
	newNPtr->copies = c;
	pPtr = nullptr;
	cPtr = b->firstBook;
	while (cPtr != nullptr && a.compare(cPtr->author_name) > 0)
	{
		pPtr = cPtr;
		cPtr = cPtr->next;
	}
	newNPtr->next = cPtr;
	if (pPtr == nullptr)
	{
		 b->firstBook = newNPtr;
	}
	else
		pPtr->next = newNPtr;

	return newNPtr;
}

void Library::printBranch(std::string s)
{
	int bIndex = 0;
	bool found = false;

	while (bIndex <= free)
	{
		if (bArray[bIndex].branch_name == s)
		{
			found = true;
			node* temp = bArray[bIndex].firstBook;
			cout << "Branch name: " << bArray[bIndex].branch_name << endl;
			cout << "Book list:" << endl;
			while (temp != nullptr)
			{
				cout << "=============" << endl;
				cout << "Author: " << temp->author_name << endl;
				cout << "Title: " << temp->book_title << endl;
				cout << "Copies: " << temp->copies << endl;
				temp = temp->next;
			}
			cout <<  "=============" << endl << endl;
		}
		bIndex++;
	}
	if (!found)
	{
		cout << "Branch not found." << endl << endl;
	}
}

void Library::checkoutBook()
{
	int bIndex = 0;
	bool foundBranch = false; bool foundBook = false;
	string titleName; string branchName; string authorName;

	//============================================================
	//Get needed info

	cout << endl << "Enter the name of the desired branch: " << endl;
	cin.ignore();
	getline(cin, branchName);

	cout << "Enter the name of the author: " << endl;
	getline(cin, authorName);

	cout << "Enter the name of the book: " << endl;
	getline(cin, titleName);

	//============================================================
	//Verify branch exists

	while (bIndex <= free && !foundBranch)
	{
		if (bArray[bIndex].branch_name == branchName)
			foundBranch = true;
		else
			bIndex++;
	}
	if (!foundBranch)
	{
		cout << endl << "Branch not found." <<endl << endl;
		return;
	}

	//============================================================
	//verify title and author are valid
	
	node* temp = bArray[bIndex].firstBook;
	while (temp != nullptr && !foundBook)
	{
		if (temp->author_name == authorName && temp->book_title == titleName)
			foundBook = true;
		else
			temp = temp->next;
	}
	if (!foundBook)
	{
		cout << endl << "Book not found." << endl << endl;
		return;
	}
	if (temp->copies <= 0)
	{
		cout << endl << "There are no copies left. " << endl << endl;
		return;
	}

	//============================================================
	//success

	temp->copies--;
	if (temp->copies <= 0)
		deleteBook(&bArray[bIndex], authorName, titleName);
	cout << endl << "Book successfully checked out." << endl << endl;

}

void Library::deleteBook(branch* br, std::string a, std::string t)
{
	node* delPtr = nullptr; node* curPtr = nullptr;
	if (br->firstBook->author_name == a && br->firstBook->book_title == t)
	{
		delPtr = br->firstBook;
		br->firstBook = br->firstBook->next;
	}
	else
	{
		curPtr = br->firstBook;
		while (curPtr->next->author_name != a && curPtr->next->book_title != t)
		{
			curPtr = curPtr->next;
			delPtr = curPtr->next;
		}
		curPtr->next = curPtr->next->next;
	}
	delete delPtr;
}

void Library::returnBook(std::string s, std::string a, std::string t)
{
	int bIndex = 0; bool foundBranch = false;
	while (bIndex <= free && !foundBranch)
	{
		if (bArray[bIndex].branch_name == s)
			foundBranch = true;
		else
			bIndex++;
	}
	if (!foundBranch)
	{
		cout << endl << "Branch not found. " << endl << endl;
		return;
	}

	branch* bPtr = &bArray[bIndex];
	node* temp = bArray[bIndex].firstBook;
	while (temp != nullptr)
	{
		if (temp->author_name == a && temp->book_title == t)
		{
			temp->copies++;
			cout << endl << "Book successfully returned. " << endl << endl;
			return;
		}
		temp = temp->next;
	}

	add(a, t, 1, bPtr);
	cout << endl << "Book successfully returned. " << endl << endl;
}

void Library::getCopies(std::string s, std::string a, std::string t)
{
	int bIndex = 0; bool foundBranch = false;
	while (bIndex <= free && !foundBranch)
	{
		if (bArray[bIndex].branch_name == s)
			foundBranch = true;
		else
			bIndex++;
	}
	if (!foundBranch)
	{
		cout << endl << "Branch not found. " << endl << endl;
		return;
	}

	node* temp = bArray[bIndex].firstBook;
	while (temp != nullptr)
	{
		if (temp->author_name == a && temp->book_title == t)
		{
			cout << endl << "Copies left: " << temp->copies << endl << endl;
			return;
		}
		temp = temp->next;
	}

	cout << endl << "Book not found." << endl << endl;
}
