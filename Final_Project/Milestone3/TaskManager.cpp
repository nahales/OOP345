/*************************
* OOP345 - Milestone 3
* Author: Nahal Esmaeili
* Prof: John Blair
* August 11, 2017
*************************/

#include <algorithm>
#include <vector>
#include "Task.h"
#include "TaskManager.h"
#include "ItemManager.h"

void TaskManager::validate(std::ostream& os) 
{
	for (size_t i = 0; i < std::vector<Task>::size(); i++) 
	{
		for (size_t n = 0; n < std::vector<Task>::size(); n++) 
		{
			if (i != n) 
			{
				std::vector<Task>::at(i).validate(std::vector<Task>::at(n));
			}
		}
	}
}

void TaskManager::validate(const ItemManager& itemManager, std::ostream& os) 
{
	int i = 0;
	for (size_t i = 0; i < itemManager.size(); i++) 
	{
		for (size_t j = 0; j < std::vector<Task>::size(); j++) 
		{
			if (itemManager.at(i).getName() == std::vector<Task>::at(j).getName()) 
			{ 
				break; 
			}
			if (i == std::vector<Task>::size() - 1) 
			{
				os << itemManager.at(i).getName() << " is unavailable." << std::endl; 
			}
		}
	}

	for (size_t i = 0; i < itemManager.size(); i++) 
	{
		for (size_t j = 0; j < std::vector<Task>::size(); j++) 
		{
			if (itemManager.at(i).getRemover() == std::vector<Task>::at(j).getName()) 
			{ 
				break; 
			} 
			if (j == std::vector<Task>::size() - 1) 
			{ 
				os << itemManager.at(i).getRemover() << " is unavailable." << std::endl; 
			}
		}
	}
}

void TaskManager::display(std::ostream& os) const 
{
	for (size_t i = 0; i < std::vector<Task>::size(); i++) 
	{
		std::vector<Task>::at(i).display(os);
	}
}