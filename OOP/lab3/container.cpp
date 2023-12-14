#include "container.hpp"
#include <iostream>
#include <fstream>
#include <string>

List::List(){
    this->head=nullptr;
}

List::~List(){
}

List::Node::Node(){
    this->data=0;
    this->pNext=nullptr;
    size++;
}
List::Node::Node(int data, Node* pNext){
    this->data=data;
    this->pNext=pNext;
    size++;
}

// Node& List::Node=(const Node& node){
//     this->data=node.data;
//     this->pNext=node.pNext;
//     return this;
// }

void List::Node::push(int data,Node** head_ref)
{
	//Node* new_node = new Node();
    Node new_node(data,*head_ref);
	(*head_ref) = &new_node;
    size++;
}

void List::Node::print(Node* node){
    while (pNext != nullptr) {
		std::cout << node->data << " ";
		node = node->pNext;
	}
	std::cout << '\n';
}
