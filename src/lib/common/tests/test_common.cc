#include <gtest/gtest.h>

#include <fstream>
#include "../common.h"

TEST(IsDigit, Basic) {
  EXPECT_EQ(IsDigit('0'), 1);
  EXPECT_EQ(IsDigit('1'), 1);
  EXPECT_EQ(IsDigit('2'), 1);
  EXPECT_EQ(IsDigit('3'), 1);
  EXPECT_EQ(IsDigit('4'), 1);
  EXPECT_EQ(IsDigit('5'), 1);
  EXPECT_EQ(IsDigit('6'), 1);
  EXPECT_EQ(IsDigit('7'), 1);
  EXPECT_EQ(IsDigit('8'), 1);
  EXPECT_EQ(IsDigit('9'), 1);
  EXPECT_EQ(IsDigit(' '), 0);
  EXPECT_EQ(IsDigit('d'), 0);
  EXPECT_EQ(IsDigit('\n'), 0);
  EXPECT_EQ(IsDigit('\t'), 0);
  EXPECT_EQ(IsDigit('\0'), 0);
}

TEST(Pow, Basic) {
  EXPECT_EQ(Pow(2,2), 4);
  EXPECT_EQ(Pow(3,10), 59049);
  EXPECT_EQ(Pow(2,20), 1048576);
}

TEST(Atoi, Basic) {
  EXPECT_EQ(Atoi("123"), 123);
  EXPECT_EQ(Atoi("        123"), 123);
  EXPECT_EQ(Atoi("+123"), 123);
  EXPECT_EQ(Atoi("-123"), -123);
  EXPECT_EQ(Atoi("+-123"), 0);
  EXPECT_EQ(Atoi("    -123"), -123);
  EXPECT_EQ(Atoi("\n\t\n\n  \n    -123"), -123);
}

TEST(ReadUserNumericInput, Basic) {
	std::ifstream input;
	double* userInput = new double[2] {0, 0};
	input.open("./tests/testRUNI-basic.txt", std::ifstream::in);
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 0);
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 1);
	delete [] userInput;

	userInput = new double[2] {0, 0};
  EXPECT_EQ(ReadUserNumericInput(input, userInput), -12);
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 123);
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 456);
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 789);
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 789); //start with 0
	delete [] userInput;
}

TEST(ReadUserNumericInput, PositiveFloat) {
	std::ifstream input;
	double* userInput = new double[2] {0, 0};

	input.open("./tests/testRUNI-positive.txt", std::ifstream::in);

  EXPECT_EQ(ReadUserNumericInput(input, userInput),789.12300000);
	delete [] userInput;

	userInput = new double[2] {0, 0};
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 789.00012300);
	delete [] userInput;

	userInput = new double[2] {0, 0};
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 789.000123000000001234);
	delete [] userInput;

	userInput = new double[2] {0, 0};
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 12341235789.00012300000000123);
	delete [] userInput;

	userInput = new double[2] {0, 0};
  EXPECT_EQ(ReadUserNumericInput(input, userInput), 12341235789.00012300000000123);
	delete [] userInput;
}

TEST(ReadUserNumericInput, NegativeFloat) {
	std::ifstream input;
	double* userInput = new double[2] {0, 0};

	input.open("./tests/testRUNI-negative.txt", std::ifstream::in);

  EXPECT_EQ(ReadUserNumericInput(input, userInput), -789.12300000);
	delete [] userInput;

	userInput = new double[2] {0, 0};
  EXPECT_EQ(ReadUserNumericInput(input, userInput), -789.00012300);
	delete [] userInput;

	userInput = new double[2] {0, 0};
  EXPECT_EQ(ReadUserNumericInput(input, userInput), -789.000123000000001234);
	delete [] userInput;

	userInput = new double[2] {0, 0};
  EXPECT_EQ(ReadUserNumericInput(input, userInput), -12341235789.00012300000000123);
	delete [] userInput;

	userInput = new double[2] {0, 0};
  EXPECT_EQ(ReadUserNumericInput(input, userInput), -12341235789.00012300000000123);
	delete [] userInput;
}

TEST(ReadUserNumericInput, Exceptions) {
	std::ifstream input;
	double* userInput = new double[2] {0, 0};

	input.open("./tests/testRUNI-exceptions.txt", std::ifstream::in);

  try {
    ReadUserNumericInput(input, userInput);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(std::string("Only numeric values are allowed!"), e.what());
  }
  try {
    ReadUserNumericInput(input, userInput);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(std::string("Only numeric values are allowed!"), e.what());
  }
  try {
    ReadUserNumericInput(input, userInput);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(std::string("Only numeric values are allowed!"), e.what());
  }
  try {
    ReadUserNumericInput(input, userInput);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(std::string("Only numeric values are allowed!"), e.what());
  }
  try {
    ReadUserNumericInput(input, userInput);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(std::string("Only numeric values are allowed!"), e.what());
  }
  try {
    ReadUserNumericInput(input, userInput);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(std::string("Only numeric values are allowed!"), e.what());
  }
  try {
    ReadUserNumericInput(input, userInput);
  } catch (std::invalid_argument &e) {
    ASSERT_EQ(std::string("Only numeric values are allowed!"), e.what());
  }
	delete [] userInput;
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
