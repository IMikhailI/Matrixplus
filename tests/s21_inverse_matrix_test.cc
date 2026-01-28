#include "s21_test.h"

TEST(InverseTest, CorrectMatrix_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  A = A.InverseMatrix();
  S21Matrix C(2, 2);
  C(0, 0) = 2.0;
  C(0, 1) = -(1.0 / 3.0);
  C(1, 0) = -3.0;
  C(1, 1) = 2.0 / 3.0;
  bool res = A.EqMatrix(C);
  EXPECT_TRUE(res);
}
TEST(InverseTest, CorrectMatrix_2) {
  S21Matrix A(1, 1);
  A(0, 0) = 2.0;
  A = A.InverseMatrix();
  S21Matrix C(1, 1);
  C(0, 0) = 1 / 2.0;
  bool res = A.EqMatrix(C);
  EXPECT_TRUE(res);
}
TEST(InverseTest, IncorrectMatrix_1) {
  S21Matrix A(3, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
}
TEST(InverseTest, IncorrectMatrix_2) {
  S21Matrix A;
  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
}
TEST(InverseTest, IncorrectMatrix_3) {
  S21Matrix A(2, 2);
  A(0, 0) = 1.0;
  A(0, 1) = 1.0;
  A(1, 0) = 1.0;
  A(1, 1) = 1.0;
  EXPECT_THROW(A.InverseMatrix(), std::invalid_argument);
}