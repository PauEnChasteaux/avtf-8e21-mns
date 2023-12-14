#pragma once
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <string>
#include <vector>

class container{

};

class List {
	class Node {
		Node* head;
		int size;
	public:
		Node* pNext;
		int data;
		Node();
		Node(int data, Node* pNext = nullptr);

		// Node& operator=(const Node& node);

		void push(int data, Node** head_ref);
		void print(Node* node);
	};
	Node* head;
	int size;
public:
	List();
	~List();
};

#endif /* CONTAINER_HPP */
