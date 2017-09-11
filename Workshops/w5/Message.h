#pragma once
/*************************
* OOP345 - Workshop 5
* Author: Nahal Esmaeili
* Prof: John Blair
* August 10, 2017
*************************/

#include <iostream>
#include <fstream>
#include <string>

namespace w5
{
	class Message
	{
	public:
		char *message;
		int num;
		~Message();
		Message(std::ifstream&, char);
		bool empty() const;
		void display(std::ostream&) const;
	};
}