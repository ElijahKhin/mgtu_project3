#ifndef COMMON_H
#define COMMON_H

#include <iostream>

int IsDigit(int ch) noexcept;
int Atoi(const char* str) noexcept;
double Pow(double value, int power) noexcept;
int Factorial(int value) noexcept;
double ReadUserNumericInput(std::istream& input, double*& userInput);


#endif
