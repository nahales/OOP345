/*************************
* OOP345 - Workshop 5
* Author: Nahal Esmaeili
* Prof: John Blair
* August 10, 2017
*************************/
#include "Notifications.h"
using namespace std;
using namespace w5;

Notifications::Notifications()
{
	notification = new char[1024];
	num = 0;
}

Notifications::Notifications(const Notifications& noti)
{
	notification = new char[1024];
	num = noti.num;
	for (int i = 0; noti.notification[i] != '\0'; i++)
		notification[i] = noti.notification[i];
}

Notifications& Notifications::operator=(const Notifications& noti)
{
	if (this == &noti)
		return *this;
	if (notification != NULL)
	{
		delete[]notification;
		notification = NULL;
	}
	notification = new char[1024];
	num = noti.num;
	for (int i = 0; noti.notification[i] != '\0'; i++)
		notification[i] = noti.notification[i];
	return *this;
}

Notifications::Notifications(Notifications&& noti) :notification(noti.notification)
{
	noti.notification = NULL;
	num = noti.num;
}

Notifications& Notifications::operator=(Notifications&& noti)
{
	auto notification = this->notification;
	this->notification = noti.notification;
	noti.notification = notification;
	num = noti.num;
	return *this;
}


Notifications::~Notifications()
{
	if (notification != NULL)
		delete notification;
}

void Notifications::operator+=(const Message& msg)
{
	int index = 0;
	if (num > 0)
	{
		notification[num] = '\n';
		num++;
	}
	for (int i = 0; msg.message[i] != '\0'; i++)
	{
		notification[num + i] = msg.message[i];
	}
	num = num + msg.num;
	notification[num] = '\0';
}

void Notifications::display(std::ostream& os) const
{
	os << notification << endl;
}