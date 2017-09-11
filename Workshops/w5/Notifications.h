#pragma once
/*************************
* OOP345 - Workshop 5
* Author: Nahal Esmaeili
* Prof: John Blair
* August 10, 2017
*************************/

#include "Message.h"

namespace w5
{
	class Notifications
	{
	public:
		char *notification;
		int num;
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message&);
		void display(std::ostream&) const;
	};
}
