#include "s21_test.h"

TEST(Indexation, OutOfRange) {
  S21Matrix A(1, 1);
  EXPECT_THROW(A(2, 2), std::invalid_argument);
}
TEST(MutatorsTest, CorrectMatrix_1) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;
  A.SetRows(2);
  A.SetCols(2);
  S21Matrix C(2, 2);
  C(0, 0) = 2.0;
  C(0, 1) = 0.0;
  C(1, 0) = 0.0;
  C(1, 1) = 0.0;
  bool res = A.EqMatrix(C);
  EXPECT_TRUE(res);
}
TEST(MutatorsTest, CorrectMatrix_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 0.0;
  A(1, 0) = 0.0;
  A(1, 1) = 0.0;
  A.SetRows(1);
  A.SetCols(1);
  S21Matrix C(1, 1);
  C(0, 0) = 2.0;
  bool res = A.EqMatrix(C);
  EXPECT_TRUE(res);
}
TEST(MutatorsTest, InorrectMatrix_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 0.0;
  A(1, 0) = 0.0;
  A(1, 1) = 0.0;
  EXPECT_THROW(A.SetRows(-1), std::invalid_argument);
}