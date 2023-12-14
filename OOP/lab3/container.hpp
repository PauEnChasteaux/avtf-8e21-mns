#pragma once
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <string>
#include <vector>

class Container{
public:
	Container();
	~Container();
};

class List:public Container {
    struct Node{
		Node* pNext;
		int data;
    };
    Node* head = nullptr;
    int size;
	public:

		List();
        //List(int data);
		List(int data, Node* pNext = nullptr);

		// Node& operator=(const Node& node);

		void push(int num);
		void print();
	};


#endif /* CONTAINER_HPP */
