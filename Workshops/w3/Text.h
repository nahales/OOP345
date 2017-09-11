#pragma once
/*************************
* OOP345 - Workshop 3
* Author: Nahal Esmaeili
* Prof: John Blair
* August 10, 2017
*************************/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
namespace w3 {

	class Text {
		size_t	lines; //C++14
		std::string* lineTable; //C++14
	public:
		~Text();
		Text();
		Text(char* filename);
		size_t size() const; //returns number of records of text data
		Text& operator= (const Text& rhs); //C++98 copy assignment operator
		Text&& operator= (Text&& rhs); //C++11 move assignment operator
		Text(const Text& rhs); // C++98 copy ctor
		Text(Text&& rhs); // C++11 move ctor
	};
} //namespace w3