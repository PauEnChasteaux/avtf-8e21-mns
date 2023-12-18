#pragma once

#include <iostream>

class Container {
public:
	virtual void push(int num) = 0;
	virtual void insert(int index, int data) = 0;
	virtual void del(int pos) = 0;
	virtual void printAll() = 0;
	virtual int getSize() = 0;
	virtual int getData(int pos) = 0;
	//virtual int operator[](int pos)const = 0;
};