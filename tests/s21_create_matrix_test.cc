#include "s21_test.h"

TEST(TestConstructor, VoidInit) {
  S21Matrix A;
  EXPECT_EQ(A.GetRows(), 0);
  EXPECT_EQ(A.GetCols(), 0);
  EXPECT_THROW(A(0, 0), std::invalid_argument);
}

TEST(TestConstructor, InitWithParameter) {
  S21Matrix A(1, 1);
  EXPECT_EQ(A.GetCols(), 1);
  EXPECT_EQ(A.GetRows(), 1);
  bool res = A(0, 0) < EPS;
  EXPECT_TRUE(res);
}
TEST(TestConstructor, InitWithParameter_err_1) {
  EXPECT_THROW(S21Matrix A(0, 0), std::invalid_argument);
}
TEST(TestConstructor, InitWithParameter_err_2) {
  EXPECT_THROW(S21Matrix A(1, 0), std::invalid_argument);
}
TEST(TestConstructor, CopyInit) {
  S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = 9.0;
  B(1, 1) = 6.0;
  S21Matrix A(B);
  EXPECT_TRUE(A.EqMatrix(B));
}

TEST(TestConstructor, MoveInit) {
  S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = 9.0;
  B(1, 1) = 6.0;
  S21Matrix C(B);
  S21Matrix A = std::move(B);
  EXPECT_EQ(B.GetCols(), 0);
  EXPECT_EQ(B.GetRows(), 0);
  EXPECT_THROW(B(0, 0), std::invalid_argument);
  EXPECT_TRUE(A.EqMatrix(C));
}
