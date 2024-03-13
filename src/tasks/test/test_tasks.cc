#include <gtest/gtest.h>

#include "../tasks.h"

/* --- TESTING TASK#1 ---*/

TEST(FirstTask, ZeroDiv) {
  EXPECT_EQ(task1(1,0), 5);
  EXPECT_EQ(task1(2,0), 15);
  EXPECT_EQ(task1(3,0), 30);
  EXPECT_EQ(task1(4,0), 50);
  EXPECT_EQ(task1(5,0), 75);
  EXPECT_EQ(task1(6,0), 105);
  EXPECT_EQ(task1(7,0), 140);
  EXPECT_EQ(task1(8,0), 180);
  EXPECT_EQ(task1(9,0), 225);
  EXPECT_EQ(task1(10,0), 275);
  EXPECT_EQ(task1(50,0), 6375);
  EXPECT_EQ(task1(500,0), 626250);
}

TEST(FirstTask, OneDiv) {
  EXPECT_EQ(task1(2,1), 0);
  EXPECT_EQ(task1(3,1), 0);
  EXPECT_EQ(task1(4,1), 0);
  EXPECT_EQ(task1(5,1), 0);
  EXPECT_EQ(task1(6,1), 0);
  EXPECT_EQ(task1(7,1), 0);
  EXPECT_EQ(task1(8,1), 0);
  EXPECT_EQ(task1(9,1), 0);
  EXPECT_EQ(task1(10,1), 0);
  EXPECT_EQ(task1(50,1), 0);
  EXPECT_EQ(task1(500,1), 0);
}

TEST(FirstTask, BasicDiv) {
  EXPECT_EQ(task1(3,2), 45);
  EXPECT_EQ(task1(4,3), 60);
  EXPECT_EQ(task1(5,4), 85);
}

TEST(FirstTask, RangeExceeded) {
  try {
    task1(1000000,0);
  } catch (std::out_of_range& e) {
    ASSERT_EQ(std::string(ERROR_RANGE_WAS_EXCEEDED), e.what());
  }
}

TEST(FirstTask, NvsM) {
  try {
    task1(5,5);
  } catch (std::invalid_argument& e) {
    ASSERT_EQ(std::string(ERROR_WRONG_INPUT), e.what());
  }
  try {
    task1(4,5);
  } catch (std::invalid_argument& e) {
    ASSERT_EQ(std::string(ERROR_WRONG_INPUT), e.what());
  }
}

/*--- TESIING TASK#2 ---*/

TEST(SecondTask,RangeExceeded) {
  try {
    task2(MAX_INT);
  } catch (std::out_of_range& e) {
    ASSERT_EQ(std::string(ERROR_RANGE_WAS_EXCEEDED), e.what());
  }
  try {
    task2(MIN_INT);
  } catch (std::out_of_range& e) {
    ASSERT_EQ(std::string(ERROR_RANGE_WAS_EXCEEDED), e.what());
  }
}

TEST(SecondTask, MAX_MIN) {
  EXPECT_EQ(task2(MAX_INT), 147456 - MAX_INT);
  EXPECT_EQ(task2(MIN_INT), 28);
}

TEST(SecondTask, NegativeA) {
  EXPECT_EQ(task2(-0.5), 28);
  EXPECT_EQ(task2(-1.521352134), 28);
  EXPECT_EQ(task2(-0.52352), 28);
  EXPECT_EQ(task2(-12344.5234), 28);
  EXPECT_EQ(task2(-212.23), 28);
  EXPECT_EQ(task2(-1252452.5235), 28);
  EXPECT_EQ(task2(-125243.5234), 28);
}

TEST(SecondTask, ZeroA) {
  EXPECT_EQ(task2(0), 147456);
}

TEST(SecondTask, PositiveA) {
  EXPECT_EQ(task2(0.5), 147455.5);
  EXPECT_EQ(task2(1.521352134), 147454.478647866);
  EXPECT_EQ(task2(0.52352), 147455.47648000001);
  EXPECT_EQ(task2(12344.5234), 135111.47659999999);
  EXPECT_EQ(task2(212.23), 147243.770000);
  EXPECT_EQ(task2(1252452.523502341123415324), -1104996.5235023412);
  EXPECT_EQ(task2(125243.52341234213521342153234), 22212.47658765786);
}

/*--- TESIING TASK#2 ---*/

TEST(ThirdTask, ZeroA) {
  EXPECT_EQ(task2(0), 147456);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
