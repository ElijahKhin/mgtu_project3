#include "tasks.h"

inline static void isWrongInput(int n, int m) {
	if (!(n > m && n > 0 && m >= 0)) 
		throw std::invalid_argument(ERROR_WRONG_INPUT);
}

inline static void isRangeExceeded(int sum) {
	if (sum < 0) throw std::out_of_range(ERROR_RANGE_WAS_EXCEEDED);
}

int task1(int n, int m) {
	int sum = 5;

	isWrongInput(n, m); // Is N bigger than M?
	if (m == 1 || m == 5) return 0; 
	for (int i = 2; n > 1; i++) {
		if (i % m) {
			sum += 5 * i; 
			n--; 
			isRangeExceeded(sum);
		}
	}
	return sum;
}
