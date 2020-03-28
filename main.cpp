#include "LinkedList.h"
#include <iostream>

int main() {
    //Singly list method check
    SinglyLinkedList arrow;

    std::cout << "Singly Linked List example:\n\n";

    for (int i = 0; i < 6; ++i) {
        arrow.addNode(i);
        arrow.displayList();
    }
    std::cout << "Removing a node...\n";
    arrow.removeNode(2);
    arrow.displayList();
    std::cout << "Removing the list\'s head...\n";
    arrow.removeNode(0);
    arrow.displayList();

    //Doubly list method check;
    DoublyLinkedList line;

    std::cout << "\nDoubly Linked List example:\n\n";
    std::cout << "Adding nodes from the head...\n";
    for (int i = 0; i < 4; ++i) {
        line.addAtHead(i);
        line.displayList();
    }
    std::cout << "Adding nodes from the tail...\n";
    for (int i = -1; i > -4; --i) {
        line.addAtTail(i);
        line.displayList();
    }
    std::cout << "Removing a node...\n";
    line.removeNode(2);
    line.displayList();
    std::cout << "Removing the list\'s head...\n";
    line.removeNode(0);
    line.displayList();
    std::cout << "Removing the list\'s tail...\n";
    line.removeNode(line.getSize()-1);
    line.displayList();

    return EXIT_SUCCESS;
}
