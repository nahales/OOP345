/*************************
* OOP345 - Workshop 2
* Author: Nahal Esmaeili
* Prof: John Blair
* August 10, 2017
*************************/

#include <string>
#include <fstream>
#include <stdlib.h>
#include "Station.h"

namespace w2 {

	Station::Station() {
		stationName = "";
		stationPasses[PASS_STUDENT] = 0;
		stationPasses[PASS_ADULT] = 0;
	}

	Station::Station(std::fstream& fs) {
		std::string name;
		std::getline(fs, name, ';');
		int s, a;
		char c;
		fs >> s;
		fs >> a;
		fs.get(c);
		if (!(c == '\n' || c == '\r')) {
			std::cerr << "expected a ->>\\n<<- and found a ->>" << c << "<<-\n";
			exit(1);
		}
		set(name, s, a);
	}

	void Station::set(const std::string& name, unsigned student, unsigned adult) {
		stationName = name;
		stationPasses[PASS_STUDENT] = student;
		stationPasses[PASS_ADULT] = adult;
	}

	void Station::update(PassType pt, int number) {
		stationPasses[pt] += number;
	}

	unsigned Station::inStock(PassType pt) const {
		return stationPasses[pt];
	}

	const std::string& Station::getName() const {
		return stationName;
	}
}