#include "s21_test.h"

TEST(TransposeTest, CorrectMatrix_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  A = A.Transpose();
  S21Matrix C(2, 2);
  C(0, 0) = 2.0;
  C(0, 1) = 9.0;
  C(1, 0) = 1.0;
  C(1, 1) = 6.0;
  bool res = A.EqMatrix(C);
  EXPECT_TRUE(res);
}
TEST(TransposeTest, InorrectMatrix_1) {
  S21Matrix A;
  EXPECT_THROW(A.Transpose(), std::invalid_argument);
}