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


#include "lines.h"
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

Lines::Lines(std::string str/**, int check**/) {
	//if (check == 2) {
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
	//}
	/**
	if (check == 1) {
		this->line = str;
		//std::cout << " not file Попробуйте ещё раз. \n";
	}**/
	//std::cout << "main Попробуйте ещё раз. \n";
	std::string s = "";
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == ' ' || line[i] == '.' || line[i] == ',')continue;
		if (line[i] == ' ' && line[i + 1] == ' ')continue;
		if ((64 < line[i] < 91) || (96 < line[i] < 123)) {
			s += line[i];
		}
		bool check = 0;
		if (line[i + 1] == ' ' || line[i + 1] == '\0') {
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
	words[0].second--;
}

Lines::Lines(std::string str, bool b){
	this->line = str;;
}

Lines::Lines(std::string line, std::vector<std::pair<std::string, int>> words){
	this->line = line;
	this-> words = words;
}

std::string Lines::get() { return line; }

Lines& Lines::operator=(const Lines& l)
{
	this->line = l.line;
	this->words = l.words;
	return *this;
}

Lines Lines::sortByLetter() {
	char constLetter = 'A';
	std::vector<std::pair<std::string, int>> tempWords;
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words.size(); j++) {
			if (words[j].first[0] == constLetter || (words[j].first[0] - 32 == constLetter)) {
				tempWords.push_back(words[j]);
			}
		}
		constLetter++;
	}
	//words = tempWords;
	Lines temp(line, tempWords);
	return temp;
}

Lines Lines::sortByWrldOrder() {
	Lines temp;
	return temp;
}

Lines Lines::sortByNumOfOccurLtoH() {
	int constOrder = 100000;
	for (int i = 0; i < words.size(); i++) {
		if (words[i].second < constOrder)  constOrder = words[i].second;
	}
	std::vector<std::pair<std::string, int>> tempWords;
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words.size(); j++) {
			if (words[j].second == constOrder) {
				tempWords.push_back(words[j]);

			}
		}
		constOrder++;
	}
	//words = tempWords;
	Lines temp(line, tempWords);
	return temp;
	
}

Lines Lines::sortByNumOfOccurHtoL() {
	int constOrder = 0;
	for (int i = 0; i < words.size(); i++) {
		if (words[i].second > constOrder)  constOrder = words[i].second;
	}
	std::vector<std::pair<std::string, int>> tempWords;
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < words.size(); j++) {
			if (words[j].second == constOrder) {
				tempWords.push_back(words[j]);

			}
		}
		constOrder--;
	}
	//words = tempWords;
	Lines temp(line,tempWords);
	return temp;
}

//std::ostream& operator<<(std::ostream& out, const Lines& l1)
//{
//	std::map<std::string, int>::iterator itr;
//	for (itr = l1.words.begin(); itr != l1.words.end(); ++itr) {
//		std::cout << '\t' << itr->first << '\t' << itr->second << '\n';
//	}
//}

int Lines::substring(Lines str) {
	int pos = -1;
	int len = 0;
	std::string s = str.get();
	for (int i = 0; this->line[i] != '\0'; i++) {
		if (this->line[i] == s[0]) {
			pos = i;
			for (int j = 0; j < length(s); j++) {
				if (s[j] != this->line[i + j]) {
					pos = -1;
					len = 0;
					break;
				}
				len++;
			}
		}
		if (len == length(s))return pos;
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

void Lines::outInTextFile(std::string str) {
	std::ofstream out(str);
	if (out.is_open())
	{
		for (int i = 0; i < words.size(); i++) {
			out << words[i].first << " " << words[i].second << '\n';
		}
	}
	out.close();
}

void Lines::outInCSVFile(std::string str) {
	std::ofstream out(str);

	if (out.is_open())
	{
		for (int i = 0; i < words.size(); i++) {
			out << words[i].first << "," << words[i].second << '\n';
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

Lines operator+(const Lines& c1, const Lines& c2)
{

	return Lines(c1.line+c2.line,c1.words);
}
