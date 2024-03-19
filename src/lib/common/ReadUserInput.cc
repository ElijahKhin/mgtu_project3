#include "common.h"

#define WRONG_INPUT "Only numeric values are allowed!"

inline static void	ThrowErrorIfNotDigit(int ch) {
	if (!IsDigit(ch)) throw std::invalid_argument(WRONG_INPUT);
}

inline static void SetSign(short& flgSign, char ch, double& userInput) {
	if (ch == '-') flgSign = -1;
	else {
		ThrowErrorIfNotDigit(ch);
		userInput = (ch - '0');
	}
}

static int ValidateUserInput(std::istream& input, double*& userInput, short idx) {
	char ch;
	int i = 0;

  for ( ; input.get(ch) && ch != '\n'; i++) {
		if (ch == '.' && !idx) return ValidateUserInput(input, userInput, 1);
		ThrowErrorIfNotDigit(ch);
		userInput[idx] = userInput[idx] * 10 + (ch - '0');
	}
	return i;
}

double ReadUserNumericInput(std::istream& input, double*& userInput) {
	char ch;
	short flgSign = 1;
	int fraction;

	input.get(ch);
	SetSign(flgSign, ch, userInput[0]);
	fraction = ValidateUserInput(input, userInput, 0);
	return flgSign * (userInput[0] + userInput[1] / Pow(10, fraction));
}
