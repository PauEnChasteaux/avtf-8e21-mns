#include <iostream>
#include "bTree.hpp"

void printVec(std::vector<int> vec){
    for(int i=0;i<vec.size();i++)
        std::cout <<vec[i]<<' ';
}

int main(){
    bTree birch;
    birch.addLeaf(5);
    birch.addLeaf(12);
    birch.addLeaf(13);
    birch.addLeaf(11);
    birch.addLeaf(3);
    birch.addLeaf(1);
    birch.addLeaf(4);
    birch.print2D();
    // birch.printTree();
    // std::cout<<'\n';
    std::vector<int> vec;
    vec=birch.DFS();
    printVec(vec);
    std::cout<<'\n';
    vec=birch.BFS();
    printVec(vec);
    std::cout<<'\n';
    std::cout<<birch.findHight()<<'\n';
    std::cout<<birch.findSmallest()<<'\n';
    std::cout<<birch.findBiggest()<<'\n';
    //birch.printChildren(12);
    std::cout<<birch.checkData(12);
    birch.removeNode(5);
    birch.print2D();
    std::cout<<'\n';

    return 0;
}
