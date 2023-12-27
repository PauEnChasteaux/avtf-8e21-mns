#include "container.hpp"
#include "list.hpp"
#include "dlist.hpp"
#include <iostream>
#include <fstream>
#include <string>



List::List() {
    Node* new_node = new Node();
    new_node->pNext = nullptr;
    head = new_node;
}

List::List(int data, Node* pNext) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->pNext = nullptr;
    head = new_node;
}

List::List(const List& m1) {
    this->head = m1.head;
}

List& List::operator=(const List& m1) {
    this->head = m1.head;
    return *this;
}

int& List::operator[]( int pos)const
{
    Node* temp = head;
    int num = 0;
    for (int i = 0; i <= pos; i++)
        temp = temp->pNext;
    return temp->data;
}

void List::push(int num) {
    Node* new_node = new Node();
    new_node->data = num;
    Node* temp = head;
    while (temp->pNext != nullptr)
        temp = temp->pNext;
    temp->pNext = new_node;
    temp->pNext->pNext = nullptr;
    size++;
}

void List::insert(int pos, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    Node* temp = head;
    for (int i = 0; i < pos; i++)
        temp = temp->pNext;
    new_node->pNext = temp->pNext;
    temp->pNext = new_node;
    size++;
}

void List::megaInsert(int pos, List* list){
    Node* temp = head;
    Node* list1 = list->head;
    Node* tlist = list->head;

    for (int i = 0; temp->pNext==nullptr; i++)
        tlist = temp->pNext;
    for (int i = 0; i < pos; i++)
        temp = temp->pNext;
    tlist->pNext = temp->pNext;
    temp->pNext = list1;
}

void List::del(int pos) {
    if (this->head == nullptr)
        return;
    Node* temp = head;
    for (int i = 0; i < pos; i++)
        temp = temp->pNext;

    Node* del = temp->pNext;
    temp->pNext = temp->pNext->pNext;
    free(del);
    size--;
}

int List::getData(int pos) {
    Node* temp = head;
    int num = 0;
    for (int i = 0; i <= pos; i++)
        temp = temp->pNext;
    return temp->data;
}

int List::getSize() {
    return size;
}

void List::printAll() {
    Node* temp = head;
    while (temp->pNext != nullptr) {
        std::cout << temp->pNext->data << " ";
        temp = temp->pNext;
    }
    std::cout << '\n';
}

List::~List() {
    free(head);
}

int dList::getSize() {
    return size;
}

dList::dList() {
    Node* new_node = new Node();
    new_node->pNext = nullptr;
    new_node->pPrev = nullptr;
    head = new_node;
}

dList::dList(int data, Node* pNext) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->pNext = nullptr;
    new_node->pPrev = nullptr;
    head = new_node;
}

dList::dList(const dList& m1) {
    this->head = m1.head;
}

dList& dList::operator=(const dList& m1) {
    this->head = m1.head;
    return *this;
}

int& dList::operator[](int pos)const
{
    Node* temp = head;
    int num = 0;
    for (int i = 0; i <= pos; i++)
        temp = temp->pNext;
    return temp->data;
}

void dList::push(int num) {
    Node* new_node = new Node();
    new_node->data = num;
    Node* temp = head;
    while (temp->pNext != nullptr)
        temp = temp->pNext;

    temp->pNext = new_node;
    new_node->pPrev = temp;
    temp->pNext->pNext = nullptr;
    size++;
}

void dList::insert(int pos, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    Node* temp = head;
    for (int i = 0; i < pos; i++)
        temp = temp->pNext;

    new_node->pNext = temp->pNext;
    new_node->pPrev = temp;
    temp->pNext->pPrev = new_node;
    temp->pNext = new_node;
    size++;
}

void dList::megaInsert(int pos, dList* list){
    Node* temp = head;
    Node* list1 = list->head;
    Node* list2 = list->head;
    Node* tlist = list->head;
    for (int i = 0; temp->pNext != nullptr; i++)
        list2 = temp->pNext;
    for (int i = 0; i < pos; i++)
        temp = temp->pNext;
    list1->pPrev = temp;
    list2->pNext = temp->pNext;
    temp->pNext = list1;
    temp->pNext->pPrev = list2;
    size++;
}

void dList::del(int pos) {
    if (this->head == nullptr)
        return;
    Node* temp = head;
    for (int i = 0; i < pos; i++)
        temp = temp->pNext;

    Node* del = temp->pNext;

    temp->pNext = temp->pNext->pNext;
    temp->pNext->pPrev = temp;
    free(del);
    size--;
}

int dList::getData(int pos) {
    Node* temp = head;
    int num = 0;
    for (int i = 0; i <= pos; i++)
        temp = temp->pNext;
    return temp->data;
    return 0;
}

void dList::printAll() {
    Node* temp = head;
    while (temp->pNext != nullptr) {
        std::cout << temp->pNext->data << " ";
        temp = temp->pNext;
    }
    std::cout << '\n';
}

dList::~dList() {
    free(head);
}
