#include "DoublyLinkedList.h"
#include <iostream>

using namespace reno_ds;

DoublyLinkedList::DoublyLinkedList() {
    this->size = 0;
    this->head = this->tail = nullptr;
}
int DoublyLinkedList::getSize() {
    return this->size;
}
DoublyLinkedList::node* DoublyLinkedList::getHead() {
    return this->head;
}
DoublyLinkedList::node* DoublyLinkedList::getTail() {
    return this->tail;
}
void DoublyLinkedList::addAtHead(int value) {
    node* add = new node;

    add->data = value;

    if (head == nullptr) {
        head = tail = add;
        add->fwd = add->back = nullptr;
    }
    else {
        add->back = head;
        add->fwd = nullptr;
        head->fwd = add;
        head = add;
    }
    this->size += 1;
}
void DoublyLinkedList::addAtTail(int value) {
    node* add = new node;

    add->data = value;

    if (tail == nullptr) {
        head = tail = add;
        add->fwd = add->back = nullptr;
    }
    else {
        add->fwd = tail;
        add->back = nullptr;
        tail->back = add;
        tail = add;
    }
    this->size += 1;
}
//Returns a node at the position pos.
DoublyLinkedList::node* DoublyLinkedList::searchNode(int pos) {
    if (pos > this->size) {
        return nullptr;
    }

    node* search = this->head;
    int i = 0;

    while (search != nullptr && i < pos) {
        ++i;
        search = search->back;
    }

    return search;

}
//Removes and deletes a node from a certain position of the list.
void DoublyLinkedList::removeNode(int pos) {
    node* removed = searchNode(pos);

    if (removed == nullptr) { //argument is out of range
        return;
    }
    if ((removed != this->head) && (removed != this->tail)) { //not head or tail nodes
        removed->back->fwd = removed->fwd;
        removed->fwd->back = removed->back;
    }
    else if (this->head == this->tail) { //last node
        this->head = this->tail = nullptr;
    }
    else if (removed == this->head) { //head node
        this->head = removed->back;
        removed->back->fwd = removed->fwd;
    }
    else if (removed == this->tail) { //tail node
        this->tail = removed->fwd;
        removed->fwd->back = removed->back;
    }
    delete removed;
    this->size -= 1;
}

void DoublyLinkedList::displayList() {
    node* next = this->head;

    std::cout << "HEAD -> ";

    while (next != nullptr) {
        std::cout << next->data << " <> ";
        next = next->back;
    }
    std::cout << "TAIL" << std::endl;
    std::cout << "List size: " << size << "\n";
}
