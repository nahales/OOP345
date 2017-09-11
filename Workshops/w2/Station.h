/*************************
* OOP345 - Workshop 2
* Author: Nahal Esmaeili
* Prof: John Blair
* August 10, 2017
*************************/

#pragma once
#include <string>
#include <fstream>
#include <iostream>

namespace w2 {

	enum PassType { PASS_STUDENT, PASS_ADULT, PASS_COUNT };

	class Station {
	private:
		std::string stationName;
		int stationPasses[PASS_COUNT];
	public:
		Station();
		Station(std::fstream& fs); 
		void set(const std::string&, unsigned, unsigned); 
		void update(PassType, int); 
		unsigned inStock(PassType) const; 
		const std::string& getName() const; 
	};
}
