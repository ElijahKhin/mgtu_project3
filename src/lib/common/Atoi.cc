#include "common.h"

int	Atoi(const char* str) noexcept {
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-') sign = -1;
	if (str[i] == '-' || str[i] == '+') i++;
	result = 0;
	while (IsDigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}
