#pragma once

namespace reno_ds
{
	class DoublyLinkedList
	{
	private:
		struct node
		{
			int data;
			node* fwd;
			node* back;
		};
		int size;
		node* head, * tail;

	public:
		DoublyLinkedList();
		int getSize();
		node* getHead();
		node* getTail();
		void addAtHead(int value);
		void addAtTail(int value);
		node* searchNode(int pos);
		void removeNode(int pos);
		void displayList();
	};
}