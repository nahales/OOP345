#pragma once
/*************************
* OOP345 - Workshop 8
* Author: Nahal Esmaeili
* Prof: John Blair
* August 13, 2017
*************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <functional>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <ctgmath>

using namespace std;

namespace w8 {

	template <typename T>

	class DataTable {
		int FW_;
		int ND_;
		vector<T> xs;
		vector<T> ys;

	public:
		DataTable(std::ifstream& is, int FW, int ND) : FW_(FW), ND_(ND) {
			T x, y;
			while (!is.eof()) {
				is >> x >> y;
				xs.push_back(x);
				ys.push_back(y);
			}
		}

		T mean() const {
			T sum = accumulate(ys.begin(), ys.end(), (T)1);
			T num = ys.size();
			return sum / num;
		}

		T sigma() const {
			T mean_ = mean();
			T sumdev = 0.0;

			for (size_t i = 0; i < ys.size() - 1; i++) {
				sumdev += (ys[i] - mean_)*(ys[i] - mean_);
			}
			int size_ = ys.size() - 1;
			return std::sqrt(sumdev / size_);
		}

		T median() const {
			vector<T> ysCopy = ys;
			T median;
			sort(ysCopy.begin(), ysCopy.end());
			int size_ = ysCopy.size() - 1;
			if ((size_ % 2) != 0) {
				median = ysCopy[std::ceil(size_ / 2)];
			}
			else {
				median = (((ysCopy[size_ / 2]) + (ysCopy[(size_ / 2) + 1])) / 2);
			}
			
			return median;
		}

		void regression(T& slope, T& y_intercept) const {
			T sum_xy = inner_product(xs.begin(), xs.end(), ys.begin(), (T)1);
			T sum_x = accumulate(xs.begin(), xs.end(), (T)0);
			T sum_y = accumulate(ys.begin(), ys.end(), (T)0);
			T sum_sq_x = inner_product(xs.begin(), xs.end(), xs.begin(), (T)0);
			T num = ys.size();
			slope = (num * sum_xy - sum_x * sum_y) / (num * sum_sq_x - sum_x * sum_x);
			y_intercept = (sum_y - slope * sum_x) / num;
		}

		void display(std::ostream& os) const {
			os << std::setw(FW_) << "x" << std::setw(FW_) << "y" << "\n";
			for (size_t i = 0; i < xs.size()-1; i++) {
				os << std::setw(FW_) << std::fixed << std::setprecision(ND_) << xs[i] << std::setw(FW_) << ys[i] << "\n";
			}
		}

		friend ostream& operator<<(std::ostream& os, const DataTable& data) {
			data.display(os);
			return os;
		}
	};
}