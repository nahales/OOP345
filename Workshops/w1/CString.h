/*************************
* OOP345 - Workshop 1
* Author: Nahal Esmaeili
* Prof: John Blair
* August 09, 2017
*************************/

#pragma once
#include <iostream>

namespace w1 {

	const int MAX = 3;

	class CString {

	private:
		char str[MAX + 1];

	public:
		CString(char* );
		void display(std::ostream&);
	};

	std::ostream& operator << (std::ostream&, CString&);

}
