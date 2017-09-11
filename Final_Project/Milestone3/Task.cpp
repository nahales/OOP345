/*************************
* OOP345 - Milestone 1
* Author: Nahal Esmaeili
* Prof: John Blair
* August 02, 2017
*************************/

#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "Task.h"
#include "Utilities.h"


size_t Task::field_width;

Task::Task(const std::string& pRecord) {
	slots = 1; 
	pNextTask[passed] = nullptr; 
	pNextTask[redirect] = nullptr; 
	size_t pos = 0;
	std::string token;
	Utilities tokenExtract;
	bool more = true;
	for (int i = 0; more; i++) { 
		token = tokenExtract.nextToken(pRecord, pos, more);
		if (!token.empty()) {
			switch (i) { 
			case 0: 
				name = token;
				break;
			case 1: 
				if (more) {
					slots = token;
				}
				break;
			case 2: 
				nextTask[passed] = token;
				break;
			case 3: 
				nextTask[redirect] = token;
				break;
			}
		}

		if (field_width < tokenExtract.getFieldWidth()) {
			field_width = tokenExtract.getFieldWidth();
		}
	}
}

bool Task::validate(const Task& task) {
	if (task.name == nextTask[passed]) {
		pNextTask[passed] = &task;
	}
	else if (task.name == nextTask[redirect]) {
		pNextTask[redirect] = &task;
	}
	return (nextTask[passed].empty() || pNextTask[passed]) 
		&& (nextTask[redirect].empty() || pNextTask[redirect]);
}

const std::string& Task::getName() const {
		
	return name;
}

void Task::display(std::ostream& os) const {
	if (pNextTask[passed]) {
		std::cout << "Task Name      :  " << std::setw(field_width + 3) << "[" + name + "]" << "[" + slots + "]" << std::endl;
		std::cout << "  Continue to  :  " << std::setw(field_width + 3) << "[" + nextTask[passed] + "]" << std::endl;
		if (!nextTask[redirect].empty()) {
			std::cout << "  Redirect to  :  " << std::setw(field_width + 3) << "[" + nextTask[redirect] + "]" << std::endl;
		}
	}
	else {
		if (nextTask[passed].empty()) { 
			std::cout << "Task Name      :  " << std::left << std::setw(field_width + 3) << "[" + name + "]" << "[1]" << std::endl;
		}
		else {
			std::cout << "Task Name      :  " << std::left << std::setw(field_width + 3) << "[" + name + "]" << "[" + slots + "]" << "*** to be validated ***" << std::endl;
			std::cout << "  Continue to  :  " << std::left << std::setw(field_width + 6) << "[" + nextTask[passed] + "]" << "*** to be validated ***" << std::endl;

			if (!nextTask[redirect].empty()) {
				std::cout << "  Redirect to  :  " << std::left << std::setw(field_width + 6) << "[" + nextTask[redirect] + "]" << "*** to be validated ***" << std::endl;

			}
		}
	}
}

size_t Task::getFieldWidth() {
	return field_width;
}

bool operator==(const Task& task_a, const Task& task_b) {
		
	return task_a.getName().compare(task_b.getName()) ? 0 : 1;
}

const Task* Task::getNextTask(Quality quantity) const {
	int vi;
	if (pNextTask[0] == nullptr) {
		throw std::string("*** Validate [" + nextTask[passed] + "]  @  [" + name + "] ***");
	}
	switch (quantity) {
	case 1:  
		vi = passed;
		break;
	case 0:  
		vi = redirect;
		break;
	}
	return pNextTask[vi];
}