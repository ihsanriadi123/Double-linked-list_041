#include <iostream>
#include <string>
using namespace std;

class node {
public:
	int noMhs;
	string name;
	node* next;
	node* prev;
};

class DOUBLELINKEDLIST {
private:
	node* start;
public:

	DOUBLELINKEDLIST();
	void addnode();
	bool search(int rollNo, node** previous, node** current);
	bool deletenode(int  rollNo);
	bool listempty();
	void ascending();
	void descending();
	void hapus();
	void searchdata();
};

DOUBLELINKEDLIST::DOUBLELINKEDLIST() {
	start = NULL;
}

void DOUBLELINKEDLIST::addnode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin.ignore();
	getline(cin, nm);
	node* newnode = new node();
	newnode->noMhs = nim;
	newnode->name = nm;

	if
}