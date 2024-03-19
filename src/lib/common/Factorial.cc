int Factorial(int value) {
	int result = 1;

	if (value == 0 || value == 1) return 1;
	for (int i = 2; i <= value; i++) result *= i;
	return result;
}
