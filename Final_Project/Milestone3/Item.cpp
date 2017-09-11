/*************************
* OOP345 - Milestone 2
* Author: Nahal Esmaeili
* Prof: John Blair
* August 08, 2017
*************************/

#include <iostream>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"

size_t Item::field_width;

Item::Item(const std::string& item)
	: description("no deatiled description"), 
	code(1)
{
	Utilities tokenExtract;
	size_t next_pos = 0;
	bool more = true;
	name = tokenExtract.nextToken(item, next_pos, more);

	if (field_width < tokenExtract.getFieldWidth())
	{
		field_width = tokenExtract.getFieldWidth();
	}

	if (name.empty() || filler.empty() || remover.empty())
	{
		throw std::string("***No Token found before the delimiter ***");
	}

	try 
	{
		if (more) { filler = tokenExtract.nextToken(item, next_pos, more); }
		if (more) { remover = tokenExtract.nextToken(item, next_pos, more); }
		if (more) { code = stoi(tokenExtract.nextToken(item, next_pos, more)); }
		if (more) { description = tokenExtract.nextToken(item, next_pos, more); }
	}
	catch (...) 
	{
		throw std::string(item + " <-- *** no token found before the delimiter ***");
	}

	if (name.empty() || filler.empty() || remover.empty()) 
	{
		throw std::string("***No Token found before the delimiter ***"); 
	}
}

bool Item::empty() const 
{
	return (name == "") ? true : false;
}

Item& Item::operator++(int n) 
{
	code++;
}

unsigned int Item::getCode() const 
{
	return code;
}

const std::string& Item::getName() const 
{
	return name;
}

const std::string& Item::getFiller() const 
{
	return filler;
}

const std::string& Item::getRemover() const 
{
	return remover;
}

void Item::display(std::ostream& os, bool full) const 
{
	os << std::setfill(' ');
	os << std::setw(field_width) << std::left << name << "[" << std::right << std::setw(CODE_WIDTH) << std::setfill('0') << code << "] From " <<
		std::setw(field_width) << std::left << std::setfill(' ') << filler << " To " << remover << std::endl <<
		std::setw(field_width + CODE_WIDTH + 3) << std::right << ": " << description << std::endl;
}