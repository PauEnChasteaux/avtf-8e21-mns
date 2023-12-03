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


#ifndef LINES_HPP
#define LINES_HPP

#include <string>
#include <map>

class Lines
{
public:
	Lines();
	//Lines(std::string line);
	Lines(std::string str,bool check);

	std::string get();
	/*friend std::ostream& operator<<(std::ostream& out, const Lines& l1);*/

	int substring(std::string s);
	int wrldCount();

	virtual ~Lines();

private:
	std::string line;
	std::map<std::string, int > words;
};

#endif /* LINES_HPP */ 
