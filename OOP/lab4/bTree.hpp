#pragma once
#ifndef BTREE_HPP
#define BTREE_HPP

#include <string>
#include <vector>

class bTree
{
    struct node {
		node* right;
        node* left;
		int data;
	};
	node* root;

    node* createLeaf(int data);
    node* returnNode(int data);
    int findHightPrivate(node* ptr);
    void addLeafPrivate(int data, node* prt);
    void printInOrderPrivate(node* ptr);
    void printTreePrivate(node* ptr);
    int findSmallestPrivate(node* ptr);
    int findBiggestPrivate(node* ptr);
    node* returnNodePrivate(int data, node* ptr);
    void removeNodePrivate(int data, node* ptr);
    void removeRootMatch();
    void removeMatch(node* parent, node* match,bool left);
    void removeSubtree(node* ptr);
    void BFSprivate(node* ptr);
    void printCurrentLvl(node* ptr, int lvl);
    void print2DPrivate(node* root);
    void print2DUtil(node* root, int space);
    //bTree subTreePrivate(node* ptr,int a,int b);
    //int returnRootData();
public:
	bTree();
    bTree(const bTree& bTree);
    bTree(std::vector<int> vec,int a, int b);
    bTree& operator=(const bTree& bTree);
    //bTree subTree(int a, int b);
    int findHight();
    void addLeaf(int data);
    std::vector<int> DFS();
    std::vector<int> BFS();
    void printTree();
    int findSmallest();
    int findBiggest();
    void printChildren(int data);
    void removeNode(int data);
    bool checkData(int data);
    void print2D();
	~bTree();

};

#endif /* BTREE_HPP */
