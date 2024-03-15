#include <gtest/gtest.h>

#include "../common.h"

TEST(common, sw_isdigit) {
  EXPECT_EQ(sw_isdigit('0'), 1);
  EXPECT_EQ(sw_isdigit('1'), 1);
  EXPECT_EQ(sw_isdigit('2'), 1);
  EXPECT_EQ(sw_isdigit('3'), 1);
  EXPECT_EQ(sw_isdigit('4'), 1);
  EXPECT_EQ(sw_isdigit('5'), 1);
  EXPECT_EQ(sw_isdigit('6'), 1);
  EXPECT_EQ(sw_isdigit('7'), 1);
  EXPECT_EQ(sw_isdigit('8'), 1);
  EXPECT_EQ(sw_isdigit('9'), 1);
  EXPECT_EQ(sw_isdigit(' '), 0);
  EXPECT_EQ(sw_isdigit('d'), 0);
  EXPECT_EQ(sw_isdigit('\n'), 0);
  EXPECT_EQ(sw_isdigit('\t'), 0);
  EXPECT_EQ(sw_isdigit('\0'), 0);
}

TEST(common, sw_pow) {
  EXPECT_EQ(sw_pow(2,2), 4);
  EXPECT_EQ(sw_pow(3,10), 59049);
  EXPECT_EQ(sw_pow(2,20), 1048576);
}

TEST(common, sw_atoi) {
  EXPECT_EQ(sw_atoi("123"), 123);
  EXPECT_EQ(sw_atoi("        123"), 123);
  EXPECT_EQ(sw_atoi("+123"), 123);
  EXPECT_EQ(sw_atoi("-123"), -123);
  EXPECT_EQ(sw_atoi("+-123"), 0);
  EXPECT_EQ(sw_atoi("    -123"), -123);
  EXPECT_EQ(sw_atoi("\n\t\n\n  \n    -123"), -123);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
