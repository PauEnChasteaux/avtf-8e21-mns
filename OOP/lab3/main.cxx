#include <iostream>
#include "container.hpp"
#include "list.hpp"
#include "dlist.hpp"
#include <string>

int main(int argc, char** argv) {
    int ch;

    Container* cont;
    List obj1;
    dList obj2;
    std::cout<<"List or dList: 1 or 2: ";
    int c;std::cin>>c;
    if(c==1)cont = &obj1;
    if(c==2)cont = &obj2;
    int data;
    int pos;
    do {
        std::cin >> ch;
        switch (ch) {
        case 1:
            std::cout << "Elemet to push: ";
            std::cin >> data;
            cont->push(data);
            std::cout << "Done" << '\n';
            break;
        case 2:
            std::cout << "Elemet to push: ";
            std::cin >> data;
            std::cout << "Pos to push: ";
            std::cin >> pos;
            cont->insert(pos, data);
            std::cout << "Done" << '\n';
            break;
        case 3:
            std::cout << "Elemet to del: ";
            std::cin >> pos;
            cont->del(pos);
            std::cout << "Done" <<'\n';

            break;
        case 4:
            std::cout << cont->getSize() << '\n';
            break;
        case 5:
            std::cout << "Elemet to print: ";
            std::cin >> pos;
            std::cout << "Element: ";
            std::cout << cont->getData(pos);
            std::cout << '\n';
            break;
        case 6:
            std::cout << "List: ";
            cont->printAll();
            break;
        case 0: std::cout << "Exit\n";
            break;
        default: std::cout << "Ha-ha \n";
        }
    } while (ch != 0);

    return 0;
}
