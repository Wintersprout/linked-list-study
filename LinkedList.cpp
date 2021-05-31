/* Author: Reno Facundo
 * Date: 2020/3
 * Description: Simple implementation of a linked list structure.
*/
#include "LinkedList.h"
#include <iostream>

using namespace reno_ds;

//Constructor
SinglyLinkedList::SinglyLinkedList() {
    this->head = nullptr;
    this->size = 0;
}
int SinglyLinkedList::getSize() {
    return this->size;
}
SinglyLinkedList::node* SinglyLinkedList::getHead() {
    return this->head;
}
//Adds an item at the head of the list.
void SinglyLinkedList::addNode(int value) {
    node* add = new node;

    add->data = value;
    add->next = head;
    this->head = add;
    this->size += 1;
}
//Returns the node of a certain position.
SinglyLinkedList::node* SinglyLinkedList::retrieveNode(int pos) {
    if (pos > this->size) {
        return nullptr;
    }

    node* search = this->head;
    int i = 0;

    while (search != nullptr && i < pos) {
        ++i;
        search = search->next;
    }

    return search;
}
//Removes and deletes a node from a certain position of the list.
void SinglyLinkedList::removeNode(int pos) {
    node* removed = retrieveNode(pos);
    //if the argument is out of range
    if (removed == nullptr) {
        return;
    }

    if (removed != this->head) {
        node* previous = this->head;

        while (previous->next != removed) {
            previous = previous->next;
        }
        previous->next = removed->next;
    } 
    else { 
        this->head = this->head->next;
    }    
    delete removed;
    this->size -= 1;
}
//Prints the list and its current size.
void SinglyLinkedList::displayList() {
    node* next = this->head;

    std::cout << "HEAD -> ";

    while (next != nullptr) {
        std::cout << next->data << " -> ";
        next = next->next;
    }
    std::cout << "END" << std::endl;
    std::cout << "List size: " << size << std::endl;
}


