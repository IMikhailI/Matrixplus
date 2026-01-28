#include "s21_test.h"

TEST(EqualTest, TrueEqual_1) {
  S21Matrix A;
  S21Matrix B;
  EXPECT_TRUE(A.EqMatrix(B));
}
TEST(EqualTest, TrueEqual_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  S21Matrix B(A);
  EXPECT_TRUE(A.EqMatrix(B));
}

TEST(EqualTest, FalseEqual_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  S21Matrix B(A);
  B(1, 1) = 3.0;
  EXPECT_FALSE(A.EqMatrix(B));
}
TEST(EqualTest, FalseEqual_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  S21Matrix B(3, 3);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = 9.0;
  B(1, 1) = 6.0;
  EXPECT_FALSE(A.EqMatrix(B));
}

TEST(EqualTest, FalseEqual_3) {
  S21Matrix A(2, 3);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = 9.0;
  B(1, 1) = 6.0;
  EXPECT_FALSE(A.EqMatrix(B));
}
TEST(EqualTest, FalseEqual_4) {
  S21Matrix A(3, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = 9.0;
  B(1, 1) = 6.0;
  EXPECT_FALSE(A.EqMatrix(B));
}
