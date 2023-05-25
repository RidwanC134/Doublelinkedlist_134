#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::addNode() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node(); // Step 1
	newNode->noMhs = nim; // Step 2
	newNode->name = nm; // Step 2

	/*insert a node in the beginning of a doubly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; // Step 3
		if (START != NULL)
			START->prev = newNode; // Step 4
		newNode->prev = NULL; // Step 5
		START = newNode; // Step 6
		return;
	}

	/*Inserting a Node Between Two Nodes in the List*/
	Node* current = START; // Step 1.a
	Node* previous = NULL; // Step 1.b
	while (current->next != NULL && current->next->noMhs < nim) // Step 1.c
	{
		previous = current; // Step 1.d
		current = current->next; // Step 1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next; // Step 4