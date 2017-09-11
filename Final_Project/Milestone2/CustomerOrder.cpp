/*************************
* OOP345 - Milestone 1
* Author: Nahal Esmaeili
* Prof: John Blair
* August 08, 2017
*************************/

#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "CustomerOrder.h"
#include "CustomerItem.h"
#include "Item.h"
#include "Utilities.h"

size_t CustomerOrder::field_width;

CustomerOrder::CustomerOrder(const std::string& custOrder) 
{
	nOrders = 0; 
	order = nullptr;
	Utilities TokenExtract;
	std::vector<std::string> token;
	size_t next_pos = 0;
	bool more = true;
	for (unsigned int counter = 0; more; counter++) 
	{
		name = TokenExtract.nextToken(custOrder, next_pos, more);

		if (more)
		{
			product = TokenExtract.nextToken(custOrder, next_pos, more);
		}

		while (more)
		{
			token.push_back(TokenExtract.nextToken(custOrder, next_pos, more));
		}
		order = new CustomerItem[token.size()];

		for (unsigned int i = 0; i < token.size(); i++)
		{
			order[i] = CustomerItem(token[i]);
		}

		if (field_width < TokenExtract.getFieldWidth())
		{
			field_width = TokenExtract.getFieldWidth();
		}
		nOrders = token.size();
	}
}

CustomerOrder::CustomerOrder(const CustomerOrder& pCustOrder) 
{
	throw std::string("Test");
}

CustomerOrder::CustomerOrder(CustomerOrder&& pCustOrder) NOEXCEPT
	: name(pCustOrder.name),
	product(pCustOrder.product),
	nOrders(pCustOrder.nOrders)
{
	order = new CustomerItem[nOrders];

	for (unsigned int i = 0; i < nOrders; i++)
	{
		order[i] = pCustOrder.order[i];
	}
	pCustOrder.order = nullptr;
	pCustOrder.name = ""; pCustOrder.product = ""; pCustOrder.nOrders = 0;
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& pCustOrder)NOEXCEPT 
{
	if (this != &pCustOrder)
	{
		delete[] order;
		name = pCustOrder.name; product = pCustOrder.product; nOrders = pCustOrder.nOrders;
		order = pCustOrder.order;
		pCustOrder.order = nullptr;
		pCustOrder.name = ""; pCustOrder.product = ""; pCustOrder.nOrders = 0;
	}
	return std::move(*this);
}

CustomerOrder::~CustomerOrder() 
{
	delete[] order;
}

bool CustomerOrder::empty() const 
{
	return (order == nullptr) ? true : false;
}

unsigned int CustomerOrder::noOrders() const
{
	return nOrders;
}

const std::string& CustomerOrder::operator[](unsigned int i) const
{
	try
	{
		std::string rName;
		rName = order[i].getName();
	}
	catch (...)
	{
	}
	return name;
}

void CustomerOrder::fill(Item& item)
{
	for (unsigned int i = 0; i < nOrders; i++)
	{
		if (order[i].asksFor(item))
		{
			order[i].fill(item.getCode());
			item++;
		}
	}
}

void CustomerOrder::remove(Item& item)
{
	for (unsigned int i = 0; i < nOrders; i++)
	{
		if (order[i].getName() == item.getName())
		{
			nOrders--;
		}
	}
}

void CustomerOrder::display(std::ostream& os) const 
{
	os << std::setw(field_width) << std::setfill(' ') << std::left << name << " :  " << product << std::endl;

	for (unsigned int i = 0; i < nOrders; i++)
		order[i].display(os);
}