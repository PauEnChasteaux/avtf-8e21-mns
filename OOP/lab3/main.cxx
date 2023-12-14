#include <iostream>
#include "container.hpp"
#include <string>

int main(int argc, char** argv){
    int ch;
    List list();
    do {
        std::cin>>ch;
        switch (ch) {
            case 1: list.push();;
            break;
            // case 2: list.deleteNode(&head,posFind(head));
            // break;
            case 3: list.printList();
            break;
            case 0: std::cout<<"Exit\n";
            break;
            default: std::cout<<"Ha-ha \n";
        }
    } while(ch!=0);

    return 0;
}
