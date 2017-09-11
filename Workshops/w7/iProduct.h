/*************************
* OOP345 - Workshop 7
* Author: Nahal Esmaeili
* Prof: John Blair
* August 13, 2017
*************************/
// Workshop 7 - STL Containers
// iProduct.h

#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

#include <iostream>
#include <fstream>

namespace w7 {

	class iProduct {
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	class Product : public iProduct {
		int prodNum;
		double cost;
	public:
		Product(const int, const double);
		double getCharge() const;
		void display(std::ostream&) const;
	};

	class TaxableProduct : public iProduct {
		int prodNum;
		double cost;
		char tax;
	public:
		TaxableProduct(int , double, char);
		double getCharge() const;
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);

}
#endif