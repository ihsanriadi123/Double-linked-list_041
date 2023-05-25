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


bool DOUBLELINKEDLIST::deletenode(int rollNo) {
	node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false)
		return false;

	if (current->next != NULL)
		current->next->prev = previous;
	if (previous != NULL)
		previous->next = current->next;
	else
		start = current->next;

	delete current;
	return true;
}

bool DOUBLELINKEDLIST::listempty() {
	return (start == NULL);
}

void DOUBLELINKEDLIST::ascending() {
	if (listempty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are:" << endl;
		node* currentnode = start;
		while (currentnode != NULL) {
			cout << currentnode->noMhs << " " << currentnode->name << endl;
			currentnode = currentnode->next;
		}
	}
}

void DOUBLELINKEDLIST::descending() {
	if (listempty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		node* currentnode = start;
		while (currentnode != NULL)
			currentnode = currentnode->next;

		while (currentnode != NULL) {
			cout << currentnode->noMhs << " " << currentnode->name << endl;
			currentnode = currentnode->prev;
		}
	}
}

void DOUBLELINKEDLIST::hapus() {
	if (listempty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DOUBLELINKEDLIST::deletenode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << "deleted" << endl;
}
void  DOUBLELINKEDLIST::searchdata() {
	if (listempty() == true) {
		cout << "\nList is empty" << endl;

	}
	node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search: ";
	int num;
	cin >> num;
	if (DOUBLELINKEDLIST::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord not found" << endl;
		cout << "\nRoll number: " << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}

int main() {
	DOUBLELINKEDLIST obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. delete a record from the list" << endl;
			cout << "3. view all records in the ascending order of roll numbers" << endl;
			cout << "4. view all records in the descending order of roll numbers" << endl;
			cout << "5. search for a record in the list" << endl;
			cout << "6. exit" << endl;
			cout << "\nEnter your choice (1-6): ";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addnode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.ascending();
				break;
			case'4':
				obj.descending();
				break;
			case'5':
				obj.searchdata();
				break;
			case'6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			cout << "check for the values entered." << endl;
		}
	}
}
