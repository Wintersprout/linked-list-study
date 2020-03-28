#include "LinkedList.h"
#include <iostream>

int main()
{
    SinglyLinkedList arrow;

    std::cout << "Singly Linked List at work:\n\n";

    for (int i = 0; i < 5; ++i) {
        arrow.addNode(i);
        arrow.displayList();
    }

    arrow.removeNode(2);
    arrow.displayList();

    DoublyLinkedList line;

    std::cout << "Doubly Linked List at work:\n\n";

    for (int i = 0; i < 3; ++i) {
        line.addAtHead(i);
        line.displayList();
    }
    for (int i = -1; i > -3; --i) {
        line.addAtTail(i);
        line.displayList();
    }

    dll::node* x = line.searchNode(1);

    std::cout << "\nThere is a " << x->fwd->data << " in front of " << x->data << " and a " << x->back->data << " at its back\n";

    line.removeNode(2);
    line.displayList();
}
