#include "tasks.h"

inline static void isRangeExceeded(double a) {
	if (!(a <= MAX_INT && a >= MIN_INT)) throw std::out_of_range(ERROR_RANGE_WAS_EXCEEDED);
}

static int productPositiveA(int result, int i) {
	result *= sw_pow(i, 2);
	if (i == 8) return result;
	return productPositiveA(result, i+2);
}

double task2(double a) {
	isRangeExceeded(a);
	if (a < 0) return 28;
	else if (a == 0) return 147456;
	return productPositiveA(1, 2) - a;
}

