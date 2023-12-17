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
            std::cout << "Elemet to push: ";
            int data; std::cin >> data;
            list.push(data);
            std::cout << '\n' << "Done" << '\n';
            break;
        case 2:
            std::cout << list.getSize() << '\n';
            break;
        case 3:
            std::cout << "Elemet to del: ";
            int pos; std::cin >> pos;
            list.del(pos);
            std::cout <<'\n' << "Done" <<'\n';
            break;
        case 4:
            std::cout << "Elemet to print: ";
            int pos1; std::cin >> pos1;
            std::cout << "Element: ";
            std::cout << list.getData(pos1);
            std::cout << '\n';
            break;
        case 5:
            std::cout << "List: ";
            list.printAll();
            std::cout << '\n';
            break;
        
        case 0: std::cout << "Exit\n";
            break;
        default: std::cout << "Ha-ha \n";
        }
    } while (ch != 0);

    return 0;
}
