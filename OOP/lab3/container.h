#pragma once
class container{

};

class List {
	class Node {
		Node* head;
		int size;
	public:
		Node* pNext;
		int data;
		Node(int data, Node* pNext = nullptr);
	};
	Node* head;
	int size;
public:
	List();
	~List();
};