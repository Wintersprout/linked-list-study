#include "Stack.h"

using namespace reno_ds;

Stack::Stack()
{
    this->top = NULL;
    this->size = 0;
}

int Stack::getSize()
{
    return size;
}
//Insert a node at the top of the stack
void Stack::push(int value)
{
    node* add = new node;

    add->data = value;
    add->next = this->top;
    this->top = add;
    this->size++;
}
//Pops data from the top of the stack.
int Stack::pop()
{
    if (this->size == 0)
    {
        return NULL;
    }
    //Buffering data before it gets deleted;
    int value = this->top->data;
    node* popped = top;
    //Updates the top of the queue and clean up the garbage;
    this->top = this->top->next;
    delete popped;

    this->size--;
    return value;
}
//Outputs the stack data
void Stack::show()
{
    node* display = this->top;

    std::cout << "TOP -> ";

    while (display != NULL)
    {
        std::cout << display->data << " -> ";
        display = display->next;
    }
    std::cout << "BOTTOM" << std::endl;
    std::cout << "Stack size: " << this->size << std::endl;
}