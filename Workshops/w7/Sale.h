#pragma once
/*************************
* OOP345 - Workshop 7
* Author: Nahal Esmaeili
* Prof: John Blair
* August 13, 2017
*************************/
#pragma once
#include <iostream>
#include <vector>
#include "iProduct.h"

namespace w7 {

	class Sale {
		std::vector<iProduct*> itemList;
	public:
		Sale(const char*);
		void display(std::ostream&);
	};

}