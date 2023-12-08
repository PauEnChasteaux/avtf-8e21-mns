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
    char ch = ' ';
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
			std::cout << "Введите название файла: ";
			std::string fStr; std::cin >> fStr;
			Lines tempLine(fStr/**, 2**/);
			s1 = tempLine;
        };
        break;
        case 2:
        {
            std::cout << "Введите искомую подстроку: \n";
            std::string str; std::cin>>str;
            std::cout << s1.substring(str) << '\n';
        };
        break;
        case 3:
        {
			int c1 = 0;
            std::cout << "Порядок слов в отображаемом результате может быть: \n"
                << "1. Алфавитный.\n"
                << "2. По порядку слов в тексте.\n"
                << "3. По количеству вхождений: от большего к меньшему.\n"
                << "4. По количеству вхождений: от меньшего к большему.\n"
                << "Выберите желаемый порядок: ";
            std::cin >> c1;
            if (c1 == 1) {
                s1.sortByLetter();
                break;
            }
            if (c1 == 2) {
                s1.sortByWrldOrder();
                break;
            }
            if (c1 == 3) {
                s1.sortByNumOfOccurHtoL();
                break;
            }
            if (c1 == 4) {
                s1.sortByNumOfOccurLtoH();
                break;
            }
            std::cout << "Попробуйте ещё раз. \n";
        };
        break;
        case 4:
        {
            std::cout << s1.wrldCount() << '\n';
        };
        break;
        case 5:
        {
			int c1 = 0;
            std::cout << "Если хотите выгрузить расспределение в txt-файл нажмите 1 \n"
                << "Если хотите выгрузить расспределение в csv-файл нажмите 2 \n";
            std::cin >> c1;
            std::cout << "Введите название файла выгрузки: \n";
            
            std::string str; std::cin>>str;
            if (c1 == 1) {
                s1.outInTextFile(str);
                break;
            }
            if (c1 == 2) {
                s1.outInCSVFile(str);
                break;
            }
            std::cout << "Попробуйте ещё раз. \n";
        };
        break;
        default:
            continue;
            break;
        }
    } while (n != 0);
    std::cout << "Программма завершена успешно. \n";



    return 0;
}
