#pragma once
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <string>
#include <vector>

class Container {

public:
	int size;
	
	Container();

	int getSize();

	~Container();
};

class List :public Container {
	struct Node {
		Node* pNext;
		int data;
	};
	Node* head = nullptr;
public:

	List();
	List(int data, Node* pNext = nullptr);

	List(const List& m1);
	List& operator=(const List& m1);

	void push(int num);
	void del(int pos);

	int getData(int pos);
	void printAll();

	~List();
};

class dList :public Container {
	struct Node {
		Node* pNext;
		Node* pPrev;
		int data;
	};
	Node* head = nullptr;

public:
	dList();
	dList(int data, Node* pNext = nullptr);

	dList(const dList& m1);
	dList& operator=(const dList& m1);

	void push(int num);
	void del(int pos);

	int getData(int pos);
	void printAll();

	~dList();
};
#endif /* CONTAINER_HPP */
