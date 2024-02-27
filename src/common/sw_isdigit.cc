int sw_isdigit(int ch) noexcept {
	if (!(ch >= 48 && ch <= 57)) return 0;
	return 1;
}
