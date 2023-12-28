#include "bTree.hpp"
#include <iostream>
#include <vector>

#define COUNT 10
//#include "bTree.hpp"

bTree::bTree(){
    root=nullptr;
}

bTree::node* bTree::createLeaf(int data){
    node* tmp = new node();
    tmp->right = nullptr;
    tmp->left = nullptr;
    tmp->data = data;
    return tmp;
}

bTree::bTree(const bTree& bTree){
    this->root=bTree.root;
}

bTree& bTree::operator=(const bTree& bTree){
    this->root = bTree.root;
    return *this;
}

int bTree::findHight(){
    return findHightPrivate(root);
}

int bTree::findHightPrivate(node* ptr){
    if(ptr==nullptr)return 0;
    else{
        int lDepth = findHightPrivate(ptr->left);
        int rDepth = findHightPrivate(ptr->right);
        if (lDepth > rDepth)return (lDepth + 1);
        else return (rDepth + 1);
    }
}

void bTree::addLeaf(int data){
    addLeafPrivate(data, root);
}

void bTree::addLeafPrivate(int data, node* ptr){
    if(root==nullptr){
        root=createLeaf(data);
    }
    else if(data<ptr->data){
        if(ptr->left!=nullptr){
            addLeafPrivate(data, ptr->left);
        }
        else
        {
            ptr->left=createLeaf(data);
        }
    }
    else if(data>ptr->data){
        if(ptr->right!=nullptr){
            addLeafPrivate(data, ptr->right);
        }
        else
        {
            ptr->right=createLeaf(data);
        }
    }else{
        std::cout<< "Data already in tree \n";
    }
}

std::vector<int> vec;
std::vector<int> bTree::DFS(){
    std::vector<int> vec1;
    printInOrderPrivate(root);
    vec1=vec;
    return vec1;
}
void bTree::printInOrderPrivate(node* ptr){
    if(root != nullptr){
        if(ptr->left!=nullptr){
            printInOrderPrivate(ptr->left);
        }
        vec.push_back(ptr->data);
        //std::cout << ptr->data<<" ";
        if(ptr->right!=nullptr){
            printInOrderPrivate(ptr->right);
        }
    }else{
        std::cout<<"Tree is empty.\n";
    }
}

void bTree::printTree(){
    printTreePrivate(root);
}

void bTree::printTreePrivate(node* ptr){
    if(ptr==nullptr)return;
    std::cout<<ptr->data<<' ';
    printTreePrivate(ptr->left);
    printTreePrivate(ptr->right);
}

int bTree::findSmallest(){
    return findSmallestPrivate(root);
}

int bTree::findSmallestPrivate(node* ptr){
    if(root==nullptr){
        std::cout << "Empty\n";
        return -1;
    }else{
        if(ptr->left!=nullptr){
            return findSmallestPrivate(ptr->left);
        }else{
            return ptr->data;
        }
    }
}

int bTree::findBiggest(){
    return findBiggestPrivate(root);
}

int bTree::findBiggestPrivate(node* ptr){
    if(root==nullptr){
        std::cout << "Empty\n";
        return -1;
    }else{
        if(ptr->right!=nullptr){
            return findBiggestPrivate(ptr->right);
        }else{
            return ptr->data;
        }
    }
}

bTree::node* bTree::returnNode(int data){
    return returnNodePrivate(data, root);
}

bTree::node* bTree::returnNodePrivate(int data, node* ptr){
    if(ptr!=nullptr){
        if(ptr->data==data){
            return ptr;
        }else{
            if(data<ptr->data){
                return returnNodePrivate(data, ptr->left);
            }else{
                return returnNodePrivate(data, ptr->right);
            }
        }
    }else{
        return nullptr;
    }
}

int bTree::returnRootData(){
    if(root!=nullptr){
        return root->data;
    }else{
        return -1;
    }
}

bool bTree::checkData(int data){
    node* ptr = returnNode(data);
    if(ptr!=nullptr)return true;
    else return false;
}

void bTree::printChildren(int data){
    node* ptr = returnNode(data);
    if(ptr!=nullptr){
        std::cout << "Parent node: "<<ptr->data<<'\n';
        ptr->left==nullptr?
        std::cout<<"Left child = nullptr\n" :
        std::cout<<"Left child = "<< ptr->left->data<<'\n';
        ptr->right==nullptr?
        std::cout<<"Left child = nullptr\n" :
        std::cout<<"Left child = "<< ptr->right->data<<'\n';

    }else{
        std::cout<<"Uvi, nichego podobnogo here net\n";
    }
}

void bTree::removeNode(int data){
    removeNodePrivate(data, root);
}
void bTree::removeNodePrivate(int data, node* ptr){
    if(root!=nullptr){
        if(root->data==data){
            removeRootMatch();
        }else{
            if(data<ptr->data&&ptr->left!=nullptr){
                ptr->left->data==data?
                removeMatch(ptr, ptr->left, true):
                removeNodePrivate(data, ptr->left);
            }else
            if(data>ptr->data&&ptr->right!=nullptr){
                ptr->right->data==data?
                removeMatch(ptr, ptr->right, true):
                removeNodePrivate(data, ptr->right);
            }else{
                std::cout << "Data isn`t here\n";
            }
        }
    }else{
        std::cout<<"Birch is free\n";
    }
}

void bTree::bTree::removeRootMatch(){
    if(root!=nullptr){
        node* delPtr=root;
        int rootData=root->data;
        int smallestInRightSubtree;
        if(root->left==nullptr&&root->right==nullptr){
            root=nullptr;
            delete delPtr;
        }else
        if(root->left==nullptr&&root->right!=nullptr){
            root=root->right;
            delPtr->right=nullptr;
            delete delPtr;
            //std::cout<<"Node with data="<<rootData<<" was deleted. \n";
        }else
        if(root->left!=nullptr&&root->right==nullptr){
            root=root->left;
            delPtr->left=nullptr;
            delete delPtr;
            //std::cout<<"Node with data="<<rootData<<" was deleted. \n";
        }else{
            smallestInRightSubtree = findSmallestPrivate(root->right);
            removeNodePrivate(smallestInRightSubtree,root);
            root->data=smallestInRightSubtree;
            //std::cout<<"Node with data="<<rootData<<" was overwritten with "<< root->data<<'\n';
        }
    }else{
        //std::cout<<"Birch is empty\n";
    }
}

void bTree::removeMatch(node* parent, node* match,bool left){
    if(root!=nullptr){
        node* delPtr;
        int matchData = match->data;
        int smallestInRightSubtree;

        if(match->left==nullptr&&match->right==nullptr){
            delPtr=match;
            left==true?parent->left=nullptr:parent->right=nullptr;
            delete delPtr;
            //std::cout<<matchData<<" was deleted\n";
        }else
        if(match->left==nullptr&&match->right!=nullptr){
            left==true?parent->left=match->right:parent->right=match->right;
            match->right=nullptr;
            delPtr=match;
            delete delPtr;
            //std::cout<<matchData<<" was deleted\n";
        }else
        if(match->left!=nullptr&&match->right==nullptr){
            left==true?parent->left=match->left:parent->right=match->left;
            match->left=nullptr;
            delPtr=match;
            delete delPtr;
            //std::cout<<matchData<<" was deleted\n";
        }else{
            smallestInRightSubtree=findSmallestPrivate(match->right);
            removeNodePrivate(smallestInRightSubtree,match);
            match->data=smallestInRightSubtree;
        }
    }else{
        //std::cout<<"Tree is empty\n";
    }
}
std::vector<int> vec2;
std::vector<int> bTree::BFS(){
    std::vector<int> vec22;
    BFSprivate(root);
    vec22=vec2;
    return vec22;
}

void bTree::BFSprivate(node* ptr){
    int h = findHightPrivate(ptr);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLvl(ptr, i);
}

void bTree::printCurrentLvl(node* ptr, int level)
{
    if (ptr == NULL)
        return;
    if (level == 1)
        vec2.push_back(ptr->data);
    else if (level > 1) {
        printCurrentLvl(ptr->left, level - 1);
        printCurrentLvl(ptr->right, level - 1);
    }
}

void bTree::print2D(){
    print2DPrivate(root);
}

void bTree::print2DPrivate(node* ptr){
     print2DUtil(ptr, 0);
}

void bTree::print2DUtil(node* ptr, int space)
{
    if (ptr == NULL)
        return;
    space += COUNT;
    print2DUtil(ptr->right, space);
    std::cout << '\n';
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << ptr->data << "\n";
    print2DUtil(ptr->left, space);
}

bTree::~bTree() {
    removeSubtree(root);
}

void bTree::removeSubtree(node* ptr){
    if(ptr!=nullptr){
        if(ptr->left!=nullptr){
            removeSubtree(ptr->left);
        }
        if(ptr->right!=nullptr){
            removeSubtree(ptr->right);
        }
        //std::cout<<"Node with data "<<ptr->data<<" was deleted.\n";
        delete ptr;
    }
}
