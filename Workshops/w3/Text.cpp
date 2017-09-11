/*************************
* OOP345 - Workshop 3
* Author: Nahal Esmaeili
* Prof: John Blair
* August 10, 2017
*************************/
#include <fstream>
#include "Text.h"

using namespace w3;

size_t	lines = 0;
std::string* lineTable = nullptr;
Text::~Text()
{
	delete[] lineTable;
}

Text::Text()
	 
{
	lines = 0;
	lineTable = nullptr;
}

Text::Text(char* filename)
	: lines(0), lineTable(nullptr)
{
	std::fstream is(filename, std::ios::in);
	if (is.is_open()) {
		std::string line;
		lines = 0;
		while (getline(is, line, '\n'))
			lines++;
		std::cout << "\nFile '" << filename << "' contains " << lines << "\n";
		lineTable = new std::string[lines];
		is.clear(); //reset the EOF end-of-file flag
		is.seekp(0);
		for (int line = 0; line < lines; line++) {
			getline(is, lineTable[line]);
			auto cr = lineTable[line].find('\r');
			if (cr != std::string::npos)
				lineTable[line].erase(cr);
		}
		is.close();
		//for our sanity, print out the first few lines of the file
		int count = lines;
		if (count > 10) count = 10;
		for (int i = 0; i < count; i++) {
			std::cout << "line " << i << ": '" << lineTable[i] << "'\n";
		}
		std::cout << "\n";
	}
	else {
		std::cerr << "Cannot open file'" << filename << "'\n";
	}
}

size_t Text::size() const
{
	return lines;
}

Text& Text::operator= (const Text& rhs) //C++98 copy assignment operator
{
	if (this != &rhs) {
		delete[] lineTable;
		//good practices after declere
		lineTable = nullptr;
		lines = 0;
		if (rhs.lineTable) {
			lines = rhs.lines;
			lineTable = new std::string[lines];
			for (int line = 0; line < lines; line++) {  //deep copy
				lineTable[line] = rhs.lineTable[line];
			}
		}
	}
	return *this;
}

Text&& Text::operator= (Text&& rhs) //C++11 move assignment operator
{
	if (this != &rhs) {
		delete[] lineTable;
		//steal 'brains'
		lines = rhs.lines;
		lineTable = rhs.lineTable;
		//'rhs' has no brains, turn it into a 'zombie'
		rhs.lines = 0;
		rhs.lineTable = nullptr;
	}
	return std::move(*this);
}

Text::Text(const Text& rhs) // C++98 copy ctor
	: lines(0), lineTable(nullptr)
{
	*this = rhs;
}

Text::Text(Text&& rhs) // C++11 move ctor
	: lines(0), lineTable(nullptr)
{
	*this = std::move(rhs);
}