/*************************
* OOP345 - Workshop 1
* Author: Nahal Esmaeili
* Prof: John Blair
* August 09, 2017
*************************/

#include <cstring>
#include <iostream>
#include "CString.h"

using namespace std;
namespace w1 {
	CString::CString(char* s) {
		if (s == NULL) {
			str[0] = '\0';
			return;
		}

		strncpy(str, s, MAX);
		str[MAX] = '\0';
	}

	void CString::display(std::ostream& os) {
		os << str;
	}

	std::ostream& operator << (std::ostream& os, CString& cs) {
		static int calls = 0;
		os << calls++ << ": ";
		cs.display(os);
		return os;
	}
}