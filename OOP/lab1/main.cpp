#include <iostream>
#include <vector>
#include <string> 
#include "Matrix.h"

int main()
{

    int n;
    Matrix a{};
    Matrix q{};
    std::string fName;
    setlocale(LC_ALL, "Russian");
    std::cout << "Что бы создать матрицу нажмите 1 \n";
    std::cout << "Что бы умножить матрицу на число нажмите 2 \n";
    std::cout << "Что бы транспонировать матрицу нажмите 3 \n";
    std::cout << "Что бы найти определитель матрицы нажмите 4 \n";
    std::cout << "Что бы вывести обратную матрицу 5 \n";
    std::cout << "Что бы вывести матрицу нажмите 6 \n";
    std::cout << "Что бы вывести матрицу в файл нажмите 7 \n";
    std::cout << "Что бы вывести матрицу в файл нажмите 8 \n";
    std::cout << "Что бы удалить матрицу нажмите 9 \n";
    do {
        
        std::cin >> n;
        switch (n) {
        case 1:
        {
            std::cout << "Введите название файла, содержащего матрицу: ";
            std::cin >> fName;

            Matrix b{ fName };
            a = b;
        };
        break;
        case 2:
            std::cout << "Введите число на которое хотите умножить матрицу: ";
            double num; std::cin >> num;
            a.miltOnNum(num);
        case 3:
            a = a.transp();
            break;
        case 4:
            if (a.rtnColms() != a.rtnRows()) {
                std::cout << "Матрица должна быть квадратной. \n";
                continue;
            }
            std::cout<< a.det()<<"\n";
            break;
        case 5:
            if (a.rtnColms() != a.rtnRows()) {
                std::cout << "Матрица должна быть квадратной. \n";
                continue;
            }
            if (a.det() == 0) {
                std::cout << "Определитель равен нулю. \n";
                continue;
            }
            a=a.inverse();
            break;
        case 6:
            a.printMatrix();
            break;
        case 7:
            a.outInTextFile();
            break;
        case 8:
            a.outInCSVFile();
            break;
        case 9:
            a = q;
            break;
        default:
            continue;
            break;
        }
    } while (n != 0);
    std::cout << "Программма завершена успешно. \n";
}
