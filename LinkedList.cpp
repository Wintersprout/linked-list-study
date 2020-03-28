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
    std::cout << " List size: " << size << "\n";
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
//Search the list for a value from its head and return its node.
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
    if ((removed != this->head) && (removed != this->tail)) { //not head or tail
        removed->back->fwd = removed->fwd;
        removed->fwd->back = removed->back;
    } else if (removed == this->head) { //head
        this->head = removed->back;
        removed->back->fwd = removed->fwd;
    } else if (removed == this->tail) { //tail
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
    std::cout << " List size: " << size << "\n";
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
