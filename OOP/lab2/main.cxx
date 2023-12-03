/*
 * main.cxx
 *
 * Copyright 2023 Moiseev Nikita  <mns94@deb-gf63>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <iostream>
#include "lines.hpp"
#include <string>

int main(int argc, char** argv)
{
    Lines s1{};
    Lines s2{};
    std::string fName;
    setlocale(LC_ALL, "Russian");
    std::cout << "Что бы ввести строку нажмите 1 \n";
    std::cout << "Что бы найти подстроку в строке нажмите 2 \n";
    std::cout << "Что бы распределить строку по количеству уникальных строк нажмите 3 \n";
    std::cout << "Что бы подсчитать количество слов в строке нажмите 4 \n";
    int n;
    do {
        std::cin >> n;
        switch (n) {
        case 1:
        {
            int c1 = 1;
            std::cout << "Если хотите ввести строку вручную введите 1 \n" <<"Если хотите подгрузить строку из файла введите 2 \n" ;
            std::cin >> c1;
            if (c1 == 1) {
                std::cout << "Введите строку: \n";
                std::string s;std::getline(std::cin, s);
                Lines ss(s,0);s1 = ss;
            }
            if (c1 == 2) {
                std::cout << "Введите название файла: ";
                std::string s;std::getline(std::cin, s);
                Lines ss(s,1);s1 = ss;
            }
        };
        break;
        case 2:
            std::cout << s1.wrldCount();
        case 3:
        default:
            continue;
            break;
        }
    } while (n != 0);
    std::cout << "Программма завершена успешно. \n";



	return 0;
}
