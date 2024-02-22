#include "project3.h"

inline static void isNbtM(unsigned long int n, unsigned long int m) {
	if (!(n > m)) throw std::invalid_argument(ERROR_NLTM); 
}

inline static void isBigSum(unsigned long int sum) {
	if (sum > MAX_UNSIGNED_INT) throw std::out_of_range(ERROR_BIG_SUM);
}

unsigned task1(unsigned n, unsigned m) {
	unsigned long sum = 5;

	isNbtM(n, m); // Is N bigger than M?
	if (m == 1 || m == 5) sum = 0;
	else {
		for (unsigned int i = 2; n > 1; i++)
			if (i % m) {sum += 5 * i; n--; isBigSum(sum);}
	}
	std::cout << BOLDMAGENTA << "Task#1 result: " << sum << RESET << std::endl;
	return sum;
}
