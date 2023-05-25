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

