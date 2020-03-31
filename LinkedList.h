#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace sll {
	struct node {
		int data;
		node* link;
	};
}

class SinglyLinkedList {

private:
	int size;
	sll::node* head;

public:
	SinglyLinkedList();
	int getSize();
	sll::node* getHead();
	void addNode(int value);
	sll::node* searchNode(int pos);
	void removeNode(int pos);
	void displayList();
};

namespace dll {
	struct node {
		int data;
		node* fwd;
		node* back;
	};
}

class DoublyLinkedList {
private:
	int size;
	dll::node* head, * tail;

public:
	DoublyLinkedList();
	int getSize();
	dll::node* getHead();
	dll::node* getTail();
	void addAtHead(int value);
	void addAtTail(int value);
	dll::node* searchNode(int pos);
	void removeNode(int pos);
	void displayList();
};

class Stack {
private:
	sll::node * top;
	int size;

public:
	Stack();
	int getSize();
	void push(int value);
	int pop();
	void displayStack();
};

class Queue {
private:
    sll::node* front;
    sll::node* back;
    int size;

public:
	Queue();
	int getSize();
	void enqueue(int value);
	int dequeue();
	void displayQueue();
};
#endif //LINKEDLIST_H