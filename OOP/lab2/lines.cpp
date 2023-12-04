/*
 * lines.cpp
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


#include "lines.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <map>


int length(std::string s) {
	int counter = 0;
	for (int i = 0; s[i] != '\0'; i++)counter++;
	return counter;
}

Lines::Lines() {
	this->line = "";
}

Lines::Lines(std::string str, int check) {
	if (check == 2) {
		std::ifstream in(str);
		std::string lineFromFile;
		if (in.is_open()) {
			std::getline(in, lineFromFile);
			//std::cout << "file Попробуйте ещё раз. \n";
		}
		else {
			std::cout << "Попробуйте ещё раз. \n";
		}
		in.close();
		this->line = lineFromFile;
	}
	if (check == 1) {
		this->line = str;
		//std::cout << " not file Попробуйте ещё раз. \n";
	}
	//std::cout << "main Попробуйте ещё раз. \n";
	std::string s = "";
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == ' ' && line[i + 1] == ' ')continue;
		if ((64 < line[i] < 91) || (96 < line[i] < 123)) {
			s += line[i];
		}
		bool check = 0;
		if (line[i] == ' ' || line[i + 1] == '\0') {
			if (words.empty())words.push_back(std::pair<std::string, int> {s, 1});
			for (int i = 0; i < words.size(); i++) {
				if (words[i].first == s) {
					words[i].second++;
					check = 1;
					s = "";
					break;
				}
				std::string ss = s;
				ss[0] = (ss[0] > 93) ? (ss[0] - 32) : (ss[0] + 32);
				if (words[i].first == ss) {
					words[i].second++;
					check = 1;
					s = "";
					break;
				}
			}
			if (check == 1) {
				check = 0;
				continue;
			}
			words.push_back(std::pair<std::string, int> {s, 1});
			s = "";
		}
	}
}

std::string Lines::get() { return line; }

Lines& Lines::operator=(const Lines& l)
{
	this->line = l.line;
	this->words = l.words;
	return *this;
}

void Lines::sortByLetter(){
	char constLetter = 'A';
	for (int i = 0; i < words.size(); i++) {
		if (words[i].first[0] != constLetter || (words[i].first[0]-32 != constLetter)) {
			words.push_back(words[i]);
			words.erase(words.at(i));
		}
	}
}

void Lines::sortByWrldOrder(){

}

void Lines::sortByNumOfOccur(){

}

//std::ostream& operator<<(std::ostream& out, const Lines& l1)
//{
//	std::map<std::string, int>::iterator itr;
//	for (itr = l1.words.begin(); itr != l1.words.end(); ++itr) {
//		std::cout << '\t' << itr->first << '\t' << itr->second << '\n';
//	}
//}

int Lines::substring(std::string s) {
	int pos = -1;
	for (int i = 0; this->line[i] != '\0'; i++) {
		if (this->line[i] == s[0]) {
			int currentLength = 0;
			pos = i;
			for (int j = 0, ij = i; s[j] != '\0'; j++) {

				currentLength = j + 1;
				if (s[j] != this->line[ij])break;
				ij++;
			}
			if (length(s) == currentLength) {
				break;
			}
		}
	}
	return pos;
}



int Lines::wrldCount() {
	int counter = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == ' ' && line[i + 1] == ' ')continue;
		if (line[i] == ' ' || line[i + 1] == '\0')counter++;
	}
	return counter;
}





void Lines::outInTextFile(std::string str, int n) {
	std::ofstream out(str);

	if (out.is_open())
	{
		std::map<std::string, int>::iterator itr;
		if (n == 1) {
			char ch = 'z';
			int i = 0;
			for (itr = words.begin(); itr != words.end(); ++itr) {
				if (itr->first[0] < ch) {
					ch = itr->first[0];
				}
			}
			for (itr = words.begin(); itr != words.end(); ++itr) {
				if (itr->first[0] == ch) {
					out << '\t' << itr->first << '\t' << itr->second << '\n';
					ch++;
				}
			}
		}

		if (n == 2) {
			for (itr = words.begin(); itr != words.end(); ++itr) {
				out << '\t' << itr->first << '\t' << itr->second << '\n';
			}
		}
		if (n == 3) {
			int ch = 1000;
			int i = 0;
			for (itr = words.begin(); itr != words.end(); ++itr) {
				if (itr->second < ch) {
					ch = itr->second;
				}

			}
			for (itr = words.begin(); itr != words.end(); ++itr) {
				if (itr->second == ch) {
					out << '\t' << itr->first << '\t' << itr->second << '\n';
					ch++;
				}
			}
		}
	}
	out.close();
}

void Lines::outInCSVFile(std::string str, int n) {
	std::ofstream out(str);

	if (out.is_open())
	{
		/*if (out.is_open())
		{
			std::map<std::string, int>::iterator itr;
			for (itr = words.begin(); itr != words.end(); ++itr) {
				out << itr->first << ',' << itr->second << '\n';
			}
		}*/


		std::map<std::string, int>::iterator itr;
		if (n == 1) {
			char ch = 'z';
			int i = 0;
			for (itr = words.begin(); itr != words.end(); ++itr) {
				if (itr->first[0] < ch) {
					ch = itr->first[0];
				}	
			}
			for (itr = words.begin(); itr != words.end(); ++itr) {
				if (itr->first[0] == ch) {
					out << itr->first << ',' << itr->second << '\n';
					ch++;
				}
			}
		}
		if (n == 2) {
			for (itr = words.begin(); itr != words.end(); ++itr) {
				out << itr->first << ',' << itr->second << '\n';
			}
		}
		if (n == 3) {
			int ch = 1000;
			int i = 0;
			for (itr = words.begin(); itr != words.end(); ++itr) {
				if (itr->second < ch) {
					ch = itr->second;
				}
			}
			for (itr = words.begin(); itr != words.end(); ++itr) {
				if (itr->second == ch) {
					out << itr->first << ',' << itr->second << '\n';
					ch++;
				}
			}
		}
	}
	out.close();
}

Lines::~Lines()
{
	line.clear();
	words.clear();
	//std::cout << "\nDestructor executed \n";
}
