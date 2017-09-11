/*************************
* OOP345 - Workshop 2
* Author: Nahal Esmaeili
* Prof: John Blair
* August 10, 2017
*************************/

#pragma once
#include "Station.h"
#include <fstream>

namespace w2 {
	class Stations {
	private:
		int stationsCount;
		Station *stationsTable;
		char* filename;
	public:
		Stations(char* filename);
		~Stations();
		void update() const;
		void restock() const;
		void report() const;
	};
}
