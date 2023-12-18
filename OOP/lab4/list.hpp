#pragma once

#include "container.hpp"

class List :public Container {
	struct Node {
		Node* pNext;
		int data;
	};
	Node* head = nullptr;
	int size = 0;
public:
	List();
	List(int data, Node* pNext = nullptr);

	List(const List& m1);
	List& operator=(const List& m1);
	int& operator[](int pos)const;


	void push(int num)override;
	void insert(int index, int data)override;
	void megaInsert(int pos, List* list);
	void del(int pos)override;

	int getData(int pos)override;
	int getSize()override;
	void printAll()override;

	~List();
};