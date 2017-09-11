#pragma once
/*************************
* OOP345 - Workshop 6
* Author: Nahal Esmaeili
* Prof: John Blair
* August 12, 2017
*************************/
#include <iostream>
#include <string>
#include <stdint.h>
#include <fstream>

class Grades {
private:
	std::string* stdNum;
	double* grade;
	int counter;
public:
	Grades() :stdNum(nullptr), grade(nullptr), counter(0) {}
	Grades(char* fileName) {
		try {
			std::ifstream ifs(fileName);
			if (!ifs)
				throw "File can not be opened ";
			if (ifs.is_open()) {
				std::string temp_str;
				int temp_counter = 0;

				while (getline(ifs, temp_str)) {
					temp_counter++;
				}
				ifs.clear();
				ifs.seekg(0);
				counter = temp_counter;
				stdNum = new std::string[counter];
				grade = new double[counter];

				for (int i = 0; i<counter; i++) {
					ifs >> stdNum[i];
					ifs >> grade[i];
				}
				ifs.close();
			}
		}
		catch(std::ifstream::failure fail) {
			std::cerr << "File can not be opened";
		}
	}

	template<typename GradeConvert>
	void displayGrades(std::ostream& os, GradeConvert exp) const {
		for (int i = 0; i<counter; i++) {
			os << stdNum[i] << " " << grade[i] << " " << exp(grade[i]) << std::endl;
		}
	}

};