#ifndef LINKEDLIST_H
#define LINKEDLIST_H

namespace reno_ds
{
	class SinglyLinkedList {

	private:
		struct node {
			int data;
			node* next;
		};
		int size;
		node* head;

	public:
		SinglyLinkedList();
		int getSize();
		node* getHead();
		void addNode(int value);
		node* retrieveNode(int pos);
		void removeNode(int pos);
		void displayList();
	};
}
#endif //LINKEDLIST_H