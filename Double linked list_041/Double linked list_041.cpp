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

	if (start == NULL || nim <= start->noMhs) {
		if (start != NULL && nim == start->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newnode->next = start;
		if (start != NULL)
			start->prev = newnode;
		newnode->prev = NULL;
		start = newnode;
		return;
	}

	node* current = start;
	while (current->next != NULL && nim > current->next->noMhs)
		current = current->next;

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newnode->next = current->next;
	newnode->prev = current;
	if (current->next != NULL)
		current->next->prev = newnode;
	current->next = newnode;
}

bool DOUBLELINKEDLIST::search(int rollNo, node** previous, node** current) {
	*previous = *current = start;
	while (*current != NULL && rollNo != (*current)->noMhs) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

