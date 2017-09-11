/*************************
* OOP345 - Workshop 7
* Author: Nahal Esmaeili
* Prof: John Blair
* August 13, 2017
*************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "iProduct.h"
#include "Sale.h"

namespace w7 {
	Sale::Sale(const char* fileName) {
		std::ifstream file(fileName);
		while (file) {
			iProduct* ip = readProduct(file);
			itemList.push_back(ip);
		}
	}

	void Sale::display(std::ostream& os) {
		float total = 0;
		os << std::setw(10) << "Product No" << std::setw(10) << std::fixed << "Cost" << " Taxable" << std::endl;

		for (auto i : itemList) {
			os << *i;
			total += i->getCharge();
		}
		os << std::setw(10) << "Total" << std::setw(10) << std::fixed << total << std::endl;
	}

}