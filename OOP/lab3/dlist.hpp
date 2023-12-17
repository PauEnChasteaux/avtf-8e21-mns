#pragma once

#include "container.hpp"

class dList :public Container {
	struct Node {
		Node* pNext;
		Node* pPrev;
		int data;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
    int size = 0;
public:
	dList();
	dList(int data, Node* pNext = nullptr);

	dList(const dList& m1);
	dList& operator=(const dList& m1);

	void push(int num)override;
    void insert(int index, int data)override;
	void del(int pos)override;

	int getData(int pos)override;
    int getSize()override;
	void printAll()override;

	~dList();
};
