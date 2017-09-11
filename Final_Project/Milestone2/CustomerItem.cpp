/*************************
* OOP345 - Milestone 1
* Author: Nahal Esmaeili
* Prof: John Blair
* August 08, 2017
*************************/

#include <iomanip>
#include <iostream>
#include "CustomerItem.h"
#include "Item.h"

CustomerItem::CustomerItem(const std::string& pName) 
{
	name = "";
	if (!pName.empty()) 
		name = pName;
	filled = false; code = 0;
}

bool CustomerItem::asksFor(const Item& item) const 
{
	return name == item.getName() ? true : false;
}

bool CustomerItem::isFilled() const 
{
	return filled;
}

void CustomerItem::fill(const unsigned int fill) 
{
	code = fill; 
	filled = true;
}

void CustomerItem::clear() 
{
	code = 0; 
	filled = false;
}

const std::string& CustomerItem::getName() const 
{
	return name;
}

void CustomerItem::display(std::ostream& os) const 
{
	if (isFilled())
		os << " + ";
	else 
		os << " - ";
	os << "[" << std::setw(CODE_WIDTH) << std::setfill('0') << std::right << code << "]  " << name << std::endl;
}
