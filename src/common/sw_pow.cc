int sw_pow(int value, int power) noexcept {
	int result = value;

	if (power == 0) return 1;
	for (int i = 1; i < power; i++) result *= value;
	return result;
}
