#include <gtest/gtest.h>

#include "../tasks.h"

//TEST(FirstTask, ZeroDiv) {
//  EXPECT_EQ(task1(1,0), 5);
//  EXPECT_EQ(task1(2,0), 15);
//  EXPECT_EQ(task1(3,0), 30);
//  EXPECT_EQ(task1(4,0), 50);
//  EXPECT_EQ(task1(5,0), 75);
//  EXPECT_EQ(task1(6,0), 105);
//  EXPECT_EQ(task1(7,0), 140);
//  EXPECT_EQ(task1(8,0), 180);
//  EXPECT_EQ(task1(9,0), 225);
//  EXPECT_EQ(task1(10,0), 275);
//  EXPECT_EQ(task1(50,0), 6375);
//  EXPECT_EQ(task1(500,0), 626250);
//}
//
//TEST(FirstTask, OneDiv) {
//  EXPECT_EQ(task1(2,1), 0);
//  EXPECT_EQ(task1(3,1), 0);
//  EXPECT_EQ(task1(4,1), 0);
//  EXPECT_EQ(task1(5,1), 0);
//  EXPECT_EQ(task1(6,1), 0);
//  EXPECT_EQ(task1(7,1), 0);
//  EXPECT_EQ(task1(8,1), 0);
//  EXPECT_EQ(task1(9,1), 0);
//  EXPECT_EQ(task1(10,1), 0);
//  EXPECT_EQ(task1(50,1), 0);
//  EXPECT_EQ(task1(500,1), 0);
//}
//
//TEST(FirstTask, BasicDiv) {
//  EXPECT_EQ(task1(3,2), 45);
//  EXPECT_EQ(task1(4,3), 60);
//  EXPECT_EQ(task1(5,4), 85);
//}
//
//TEST(FirstTask, RangeExceeded) {
//  try {
//    task1(1000000,0);
//  } catch (std::out_of_range& e) {
//    ASSERT_EQ(std::string(ERROR_BIG_SUM), e.what());
//  }
//}
//
//TEST(FirstTask, NvsM) {
//  try {
//    task1(5,5);
//  } catch (std::invalid_argument& e) {
//    ASSERT_EQ(std::string(ERROR_NLTM), e.what());
//  }
//  try {
//    task1(4,5);
//  } catch (std::invalid_argument& e) {
//    ASSERT_EQ(std::string(ERROR_NLTM), e.what());
//  }
//}

TEST(SecondTask, Basic) {
	task2(2);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
