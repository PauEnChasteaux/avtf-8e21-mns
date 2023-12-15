#include "container.hpp"
#include <iostream>
#include <fstream>
#include <string>

Container::Container() {
    this->size = 0;
}

int Container::getSize(){
    return size;
}

Container::~Container() {}

List::List() {
    Node* new_node = new Node();
    new_node->data = 0;
    new_node->pNext = (head);
    head = new_node;
}

List::List(int data, Node* pNext) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->pNext = (head);
    head = new_node;
}

void List::push(int num) {
    Node* new_node = new Node();
    new_node->data = num;
    new_node->pNext = (head);
    head = new_node;
    this->size++;
}

void List::del(int pos){
    if (0<=pos<size) {
        return;
    }
    if (this->head == nullptr)
        return;
    Node* temp = head;
    if (pos == 0) {
        head = temp->pNext;
        free(temp);
        size--;
        return;
    }
    for (int i = 0; temp != nullptr && i < pos; i++)
        temp = temp->pNext;
    if (temp == nullptr || temp->pNext == nullptr)
        return;
    Node* next = temp->pNext->pNext;
    free(temp->pNext);
    temp->pNext = next;
    head = temp;
    size--;
}

void List::print() {
    Node* temp = head;
    while (temp->pNext != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->pNext;
    }
    std::cout << '\n';
}
