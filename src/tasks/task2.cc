#include "tasks.h"
#include <iostream>
#include <iomanip>

static int productPositiveOrZeroA(int result, int i) {
	result *= sw_pow(i, 2);
	if (i == 8) return result; 
	return productPositiveOrZeroA(result, i+2);
}

double task2(double a) {
	double result = 28;
	
	if (a >= 0) result = productPositiveOrZeroA(1, 2) - a;
	return result;
}

int main() {
	for (int p = 1; p < 10; p++) {
	//	std::cout << std::setw(2) << p << " " << std::setprecision(p) << task2(-5.7) << std::endl;
		std::cout << std::setw(2) << p << " " << std::setprecision(p) << 0.123412521342 << std::endl;
	}
}
