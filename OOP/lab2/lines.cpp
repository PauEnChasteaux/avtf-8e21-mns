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
#include <string>

Lines::Lines(){this->line = "";}

Lines::Lines(std::string line){this->line = line;}

std::string Lines::get(){return line;}

int length(std::string s){
	int counter=0;
	for(int i=0;s[i]!='\0';i++)counter++;
	return counter;
}

int Lines::substring(std::string s){
	int pos=-1;
	for(int i=0;this->line[i]!='\0';i++){
		if(this->line[i]==s[0]){
			pos =i;
			int currentLength=0;
			for(int j=0,ij=i;s[j]!='\0';j++){
				currentLength=j+1;
				if(s[j]!=this->line[ij])break;
				ij++;
			}
			if(length(s)==currentLength)break;
		}
	}
	return pos;
}

int Lines::wrldCount(){
	int counter=0;
	for(int i=0;this->line[i]!='\0';i++)
		if(this->line[i]==' ')counter++;	
	return counter;
}

Lines::~Lines()
{
	std::cout << "\nDestructor executed \n";
}

