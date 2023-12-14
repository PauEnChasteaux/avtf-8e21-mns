#include "container.hpp"
#include <iostream>
#include <fstream>
#include <string>

Container::Container(){}

Container::~Container(){}

List::List(){
    this->head->data=0;
    this->head->pNext=nullptr;
    size++;
}

// List::List(int data){
//     this->head->data=data;
//     this->head->pNext=nullptr;
//     size++;
// }

List::List(int data, Node* pNext){
    this->head->data=data;
    this->head->pNext=pNext;
    size++;
}

// Node& List::Node=(const Node& node){
//     this->data=node.data;
//     this->pNext=node.pNext;
//     return this;
// }

void List::push(int num){
    Node* new_node = new Node();
	new_node->data = num;
	new_node->pNext = (head);
	head = new_node;
	//Node* new_node = new Node();
    //List new_node(num);
	// this->head->pNext = *new_node;
    size++;
}

void List::print(){
    while (head->pNext != nullptr) {
		std::cout << head->data << " ";
		this->head->pNext = head->pNext;
	}
	std::cout << '\n';
}
