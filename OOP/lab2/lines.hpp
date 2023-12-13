/*
 * lines.hpp
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

#pragma once
#ifndef LINES_HPP
#define LINES_HPP

#include <string>
#include <vector>

class Lines
{
public:
	Lines();
	Lines(std::string str/**, int check**/);
	Lines(std::string str, bool b);

	Lines(std::string line, std::vector<std::pair<std::string, int>> words);
	std::string get();
	Lines& operator=(const Lines& lines);
	Lines sortByLetter();
	Lines sortByWrldOrder();
	Lines sortByNumOfOccurHtoL();
	Lines sortByNumOfOccurLtoH();

	friend Lines operator+(const Lines& c1, const Lines& c2);

	int substring(Lines s);
	int wrldCount();

	void outInTextFile(std::string s);
	void outInCSVFile(std::string s);

	virtual ~Lines();

private:
	std::string line;
	std::vector<std::pair<std::string, int>> words;
	//std::map<std::string, int > words;
};

#endif /* LINES_HPP */
