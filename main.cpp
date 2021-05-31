#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "DoublyLinkedList.h"
#include <iostream>

using namespace reno_ds;

int main() {
    //Singly list method check
    SinglyLinkedList arrow;

    std::cout << "Singly Linked List example:\n";

    for (int i = 0; i < 5; ++i) {
        arrow.addNode(i);
    }

    arrow.displayList();
    std::cout << "Removing position 2...\n";
    arrow.removeNode(2);
    arrow.displayList();
    std::cout << "Removing the list\'s head...\n";
    arrow.removeNode(0);
    arrow.displayList();
    std::cout << "Removing all its elements...\n";
    while (arrow.getSize()) {
        arrow.removeNode(0);
    }
    arrow.displayList();

    //Doubly list method check;
    DoublyLinkedList line;

    std::cout << "\n\nDoubly Linked List example:\n";
    std::cout << "Adding nodes from the head...\n";
    for (int i = 0; i < 4; ++i) {
        line.addAtHead(i);
    }
    line.displayList();
    std::cout << "Adding nodes from the tail...\n";
    for (int i = -1; i > -4; --i) {
        line.addAtTail(i);
    }
    line.displayList();
    std::cout << "Removing position 2...\n";
    line.removeNode(2);
    line.displayList();
    std::cout << "Removing the list\'s head...\n";
    line.removeNode(0);
    line.displayList();
    std::cout << "Removing the list\'s tail...\n";
    line.removeNode(line.getSize()-1);
    line.displayList();
    std::cout << "Removing all its elements...\n";
    while (line.getSize()) {
        line.removeNode(0);
    }
    line.displayList();

    //Stack tests
    Stack box;
    std::cout << "\n\nStack List example:\n";

    for (int i = 10; i < 16; ++i) {
        box.push(i);
        box.show();
    }
    
    std::cout << "Popping all stacked items... ";
    while (box.getSize()) {
            std::cout << box.pop() << "... ";
    }
    std::cout << "\n";
    box.show();
        
    //Queue tests
    Queue tunnel;
    std::cout << "\nQueue List example:\n";

    for (int i = 20; i < 26; ++i) {
        tunnel.enqueue(i);
        tunnel.show();
    }
    
    std::cout << "Dequeueing all items... ";
    while (tunnel.getSize()) {
        std::cout << tunnel.dequeue() << "... ";
    }
    std::cout << "\n";
    tunnel.show();
    return EXIT_SUCCESS;
}
