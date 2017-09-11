/*************************
* OOP345 - Workshop 7
* Author: Nahal Esmaeili
* Prof: John Blair
* August 13, 2017
*************************/
#include "iProduct.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
namespace w7 {
	Product::Product(const int no, const double c) {
		prodNum = no;
		cost = c;
	}

	double Product::getCharge() const {
		return cost;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(10) << prodNum << std::setw(10) << std::fixed << std::setprecision(2) << cost << endl;
	}

	TaxableProduct::TaxableProduct(int no, double  c, char t) {
		prodNum = no;
		cost = c;
		tax = t;
	}

	double TaxableProduct::getCharge() const {
		double taxRate = 1;
		if (tax == 'H')
			taxRate = 1.13;
		if (tax == 'P')
			taxRate = 1.08;
		return (cost * taxRate);
	}

	void TaxableProduct::display(std::ostream& os) const {
		os << std::setw(10) << prodNum << std::setw(10) << std::fixed << std::setprecision(2) << cost << ' ';
		if (tax == 'H')
			os << "HST";
		if (tax == 'P')
			os << "PST";
		os << "\n";
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& i) {
		i.display(os);
		return os;
	}

	iProduct* readProduct(std::ifstream& ifs) {
		int no;
		double c;
		char t;

		iProduct* temp;

		ifs >> no >> c;
		if (ifs.get() != ' ') {
			temp = new Product(no, c);
		}
		else {
			ifs.get(t);
			temp = new TaxableProduct(no, c, t);
		}
		return temp;
	}
}