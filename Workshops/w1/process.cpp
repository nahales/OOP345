/*************************
* OOP345 - Workshop 1
* Author: Nahal Esmaeili
* Prof: John Blair
* June 06, 2017
*************************/

#include "process.h"
#include "CString.h"
#include <iostream>

void process(char* s) {
	w1::CString cs(s);
	std::cout << cs;
	std::cout << "\n";
}