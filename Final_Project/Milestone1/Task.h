#pragma once
// Task Milestone - Task Interface
// Task.h
// Chris Szalwinski
// v1.0 - 24/10/2015
// v2.0 - 23/02/2016
#include <iostream>
#include <string>

namespace m1 {
	class Task {
		std::string name;
		std::string slots;         
		std::string nextTask[2];   
		const Task* pNextTask[2]; 
		static size_t field_width; 
	public:
		enum Quality {
			passed,
			redirect
		};
		Task(const std::string&);
		bool validate(const Task&);
		const std::string& getName() const;
		//unsigned int getSlots() const;
		const Task* getNextTask(Quality) const;
		void display(std::ostream&) const;
		static size_t getFieldWidth();
	};

	bool operator==(const Task&, const Task&);
}