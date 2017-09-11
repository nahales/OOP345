/*************************
* OOP345 - Milestone 3
* Author: Nahal Esmaeili
* Prof: John Blair
* August 11, 2017
*************************/
#include "ItemManager.h"


void ItemManager::display(std::ostream& os, bool fullDesc) const 
{
	for (size_t i = 0; i < std::vector<Item>::size(); i++) 
	{
		std::vector<Item>::at(i).display(os);
	}
}