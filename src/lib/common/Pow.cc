double Pow(double value, int power) noexcept {
	double result = value;

	if (power == 0) return 1;
	for (int i = 1; i < power; i++) result *= value;
	return result;
}
