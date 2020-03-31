/* Author: Reno Facundo
 * Date: 2020/3
 * Description: Simple implementation of a linked list structure.
*/
#include "LinkedList.h"
#include <iostream>

//Constructor
SinglyLinkedList::SinglyLinkedList() {
    this->head = nullptr;
    this->size = 0;
}
int SinglyLinkedList::getSize() {
    return this->size;
}
sll::node* SinglyLinkedList::getHead() {
    return this->head;
}
//Adds an item at the head of the list.
void SinglyLinkedList::addNode(int value) {
    sll::node* add = new sll::node;

    add->data = value;
    add->link = head;
    this->head = add;
    this->size += 1;
}
//Returns the node of a certain position.
sll::node* SinglyLinkedList::searchNode(int pos) {
    if (pos > this->size) {
        return nullptr;
    }

    sll::node* search = this->head;
    int i = 0;

    while (search != nullptr && i < pos) {
        ++i;
        search = search->link;
    }

    return search;
}
//Removes and deletes a node from a certain position of the list.
void SinglyLinkedList::removeNode(int pos) {
    sll::node* removed = searchNode(pos);
    //if the argument is out of range
    if (removed == nullptr) {
        return;
    }

    if (removed != this->head) {
        sll::node* previous = this->head;

        while (previous->link != removed) {
            previous = previous->link;
        }
        previous->link = removed->link;
    } 
    else { 
        this->head = this->head->link;
    }    
    delete removed;
    this->size -= 1;
}
//Prints the list and its current size.
void SinglyLinkedList::displayList() {
    sll::node* next = this->head;

    while (next != nullptr) {
        std::cout << next->data << " <- ";
        next = next->link;
    }
    std::cout << "List size: " << size << "\n";
}

DoublyLinkedList::DoublyLinkedList() {
    this->size = 0;
    this->head = this->tail = nullptr;
}
int DoublyLinkedList::getSize() {
    return this->size;
}
dll::node* DoublyLinkedList::getHead() {
    return this->head;
}
dll::node* DoublyLinkedList::getTail() {
    return this->tail;
}
void DoublyLinkedList::addAtHead(int value) {
    dll::node* add = new dll::node;

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
    dll::node* add = new dll::node;

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
dll::node* DoublyLinkedList::searchNode(int pos) {
    if (pos > this->size) {
        return nullptr;
    }

    dll::node* search = this->head;
    int i = 0;

    while (search != nullptr && i < pos) {
        ++i;
        search = search->back;
    }

    return search;

}
//Removes and deletes a node from a certain position of the list.
void DoublyLinkedList::removeNode(int pos) {
    dll::node* removed = searchNode(pos);

    if (removed == nullptr) { //argument is out of range
        return;
    }
    if ((removed != this->head) && (removed != this->tail)) { //not head or tail nodes
        removed->back->fwd = removed->fwd;
        removed->fwd->back = removed->back;
    } else if (this->head == this->tail) { //last node
        this->head = this->tail = nullptr;
    } else if (removed == this->head) { //head node
        this->head = removed->back;
        removed->back->fwd = removed->fwd;
    } else if (removed == this->tail) { //tail node
        this->tail = removed->fwd;
        removed->fwd->back = removed->back;
    }
    delete removed;
    this->size -= 1;
}

void DoublyLinkedList::displayList() {
    dll::node* next = this->head;

    while (next != nullptr) {
        std::cout << next->data << " <> ";
        next = next->back;
    }
    std::cout << "List size: " << size << "\n";
}


Stack::Stack() {
    this->top = NULL;
    this->size = 0;
}

int Stack::getSize() {
        return size;
    }
//Insert a node at the top of the stack
void Stack::push(int value) {
    sll::node* add = new sll::node;

    add->data = value;
    add->link = this->top;
    this->top = add;
    this->size++;
}
//Pops data from the top of the stack.
int Stack::pop() {
    if (this->size == 0) {
        return NULL;
    }
    //Buffering data before it gets deleted;
    int value = this->top->data;
    sll::node* popped = top;
    //Updates the top of the queue and clean up the garbage;
    this->top = this->top->link;
    delete popped;
        
    this->size--;
    return value;
}
//Outputs the stack data
void Stack::displayStack() {
    sll::node* display = this->top;

    while (display != NULL) {
        std::cout << display->data << " <- ";
        display = display->link;
    }
    std::cout << "Stack size: " << this->size << std::endl;
}

Queue::Queue() {
    this->front = this->back = nullptr;
    this->size = 0;
}

int Queue::getSize() {
    return this->size;
}

void Queue::enqueue(int value) {
    sll::node* add = new sll::node;
    add->data = value;
    add->link = nullptr; //back node always points to nothing;
    //If the queue is not empty...
    if (this->back != nullptr) {
        this->back->link = add;
        this->back = add;
    }
    else {
        this->front = this->back = add;
    }
    this->size++;
}

int Queue::dequeue() {
    if (this->size == 0) {
        return NULL;
    }
    sll::node* out;
    //Updating the front pointer;
    out = this->front;
    this->front = this->front->link;
    //Buffering the data and cleaning up the node;
    int value = out->data;
    delete out;
    size--;

    return value;
}

void Queue::displayQueue() {
    sll::node* display = this->front;

    while (display != nullptr) {
        std::cout << display->data << " <- ";
        display = display->link;
    }
    std::cout << "Queue size: " << this->size << std::endl;
}