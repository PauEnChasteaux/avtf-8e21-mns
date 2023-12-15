#include <iostream>
#include "container.hpp"
#include <string>

int main(int argc, char** argv) {
    int ch;
    List list;
    do {
        std::cin >> ch;
        switch (ch) {
        case 1:
            int data; std::cin >> data;
            list.push(data);
            break;
        case 2: 
            int pos; std::cin >> pos;
            list.del(pos);
            break;
        case 3:
            list.print();;
            break;
        case 4:
            std::cout<<list.getSize()<<'\n';
            break;
        case 0: std::cout << "Exit\n";
            break;
        default: std::cout << "Ha-ha \n";
        }
    } while (ch != 0);

    return 0;
}
