#include "s21_test.h"

TEST(CalcComplements, CorrectMatrix_1) {
  S21Matrix A(3, 3);
  A(0, 0) = -345.0;
  A(0, 1) = 258.0;
  A(0, 2) = -109.0;
  A(1, 0) = -1035.0;
  A(1, 1) = -1074.0;
  A(1, 2) = -5783.0;
  A(2, 0) = 152.0;
  A(2, 1) = -29.0;
  A(2, 2) = -298.0;
  A = A.CalcComplements();
  S21Matrix B(3, 3);
  B(0, 0) = 152345.0;
  B(0, 1) = -1187446.0;
  B(0, 2) = 193263.0;
  B(1, 0) = 80045.0;
  B(1, 1) = 119378.0;
  B(1, 2) = 29211.0;
  B(2, 0) = -1609080;
  B(2, 1) = -1882320;
  B(2, 2) = 637560;
  EXPECT_TRUE(A.EqMatrix(B));
}
TEST(CalcComplements, CorrectMatrix_2) {
  S21Matrix A(1, 1);
  A(0, 0) = -345.0;
  A = A.CalcComplements();
  S21Matrix B(1, 1);
  B(0, 0) = -345.0;
  EXPECT_TRUE(A.EqMatrix(B));
}
TEST(CalcComplements, IncorrectMatrix_1) {
  S21Matrix A(1, 2);
  A(0, 0) = -345.0;
  EXPECT_THROW(A.CalcComplements(), std::invalid_argument);
}