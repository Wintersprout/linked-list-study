#include "Queue.h"
#include <iostream>

using namespace reno_ds;

Queue::Queue()
{
    this->front = this->back = nullptr;
    this->size = 0;
}

int Queue::getSize()
{
    return this->size;
}

void Queue::enqueue(int value)
{
    node* add = new node;
    add->data = value;
    add->next = nullptr; //back node always points to nothing;
    //If the queue is not empty...
    if (this->back != nullptr)
    {
        this->back->next = add;
        this->back = add;
    }
    else
    {
        this->front = this->back = add;
    }
    this->size++;
}

int Queue::dequeue()
{
    if (this->size == 0)
    {
        return NULL;
    }
    node* out;
    //Updating the front pointer;
    out = this->front;
    this->front = this->front->next;
    //Buffering the data and cleaning up the node;
    int value = out->data;
    delete out;
    size--;

    return value;
}

void Queue::show()
{
    node* display = this->front;

    std::cout << "FRONT -> ";

    while (display != nullptr)
    {
        std::cout << display->data << " -> ";
        display = display->next;
    }

    std::cout << "BACK" << std::endl;
    std::cout << "Queue size: " << this->size << std::endl;
}