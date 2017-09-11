/*************************
* OOP345 - Workshop 2
* Author: Nahal Esmaeili
* Prof: John Blair
* August 10, 2017
*************************/

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Stations.h"

namespace w2 {

	Stations::Stations(char* name) {
		filename = name;
		std::cout << "Stations(" << name << ")" << std::endl;
		std::fstream fs(filename);
		if (fs.is_open()) {
			fs >> stationsCount;
			std::cout << "Total Stations " << stationsCount << std::endl;
			char c;
			fs.get(c);
			if (c != ';') {
				std::cerr << "expected a ->>;<<- and found a ->>" << c << "<<-\n";
				exit(1);
			}
			fs.get(c);
			if (!(c == '\n' || c == '\r')) {
				std::cerr << "expected a ->>\\n<<- and found a ->>" << c << "<<-\n";
				exit(1);
			}
			stationsTable = new Station[stationsCount];
			for (int i = 0; i < stationsCount; i++) {
				stationsTable[i] = Station(fs);
			}
			fs.close();
		}
	}

	Stations::~Stations() {
		std::ofstream fs(filename);
		if (fs.is_open()) {
			fs << stationsCount << ";" << std::endl;
			for (int i = 0; i < stationsCount; i++) {
				fs << stationsTable[i].getName() << ";"
					<< stationsTable[i].inStock(PASS_STUDENT) << " "
					<< stationsTable[i].inStock(PASS_ADULT) << std::endl;
			}
		}
		if (stationsTable) {
			delete[]stationsTable;
		}
	}

	void Stations::update() const {
		std::cout << "\nPasses Sold :\n";
		std::cout << "---------------:\n";
		for (int i = 0; i < stationsCount; i++) {
			int student, adult;
			std::cout << stationsTable[i].getName() << "\n";
			std::cout << "Student Passes sold : ";
			std::cin >> student;
			std::cout << "Adult Passes sold : ";
			std::cin >> adult;
			stationsTable[i].update(PASS_STUDENT, -student);
			stationsTable[i].update(PASS_ADULT, -adult);
		}
	}

	void Stations::restock() const {
		std::cout << "\nPasses Added :\n";
		std::cout << "---------------:\n";
		for (int i = 0; i < stationsCount; i++) {
			int student, adult;
			std::cout << stationsTable[i].getName() << "\n";
			std::cout << "Student Passes added : ";
			std::cin >> student;
			std::cout << "Adult Passes added : ";
			std::cin >> adult;
			stationsTable[i].update(PASS_STUDENT, student);
			stationsTable[i].update(PASS_ADULT, adult);
		}
	}

	void Stations::report() const {
		//Passes in Stock : Student Adult
		//	-------------------------------
		//	Spadina               100   200
		//	Bathurst              200   300
		//	Keele                 100   100
		//	Bay                   200   200
		std::cout << "Passes in Stock : Student Adult\n";
		std::cout << "-------------------------------\n";
		for (int i = 0; i < stationsCount; i++) {
			std::cout << std::left << std::setw(19) << stationsTable[i].getName();
			std::cout << std::setw(6) << stationsTable[i].inStock(PASS_STUDENT);
			std::cout << std::setw(6) << stationsTable[i].inStock(PASS_ADULT);
			std::cout << "\n";
		}
	}
}