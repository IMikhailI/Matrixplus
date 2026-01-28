#include "s21_test.h"

TEST(MultTest, IncorrectMult_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 12.0;
  A(0, 1) = 41.0;
  A(1, 0) = -756.0;
  A(1, 1) = -53.0;
  S21Matrix B(3, 3);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = -9.0;
  B(1, 1) = 6.0;
  EXPECT_THROW(A *= B, std::invalid_argument);
}
TEST(MultTest, IncorrectMult_2) {
  S21Matrix A(3, 3);
  A(0, 0) = 12.0;
  A(0, 1) = 41.0;
  A(0, 2) = 42.0;
  A(1, 0) = -756.0;
  A(1, 1) = -53.0;
  A(1, 2) = 31.0;
  A(2, 0) = 50.0;
  A(2, 1) = 34.0;
  A(2, 2) = 29.0;
  S21Matrix B(2, 3);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = -9.0;
  B(1, 1) = 6.0;
  EXPECT_THROW(A *= B, std::invalid_argument);
}

TEST(MultTest, CorrectMult_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = -9.0;
  B(1, 1) = 6.0;
  A = A * B;
  S21Matrix C(2, 2);
  C(0, 0) = -5.0;
  C(0, 1) = 8.0;
  C(1, 0) = -36.0;
  C(1, 1) = 45.0;
  bool res = A.EqMatrix(C);
  EXPECT_TRUE(res);
}
TEST(MultTest, CorrectMult_2) {
  S21Matrix A(3, 2);
  A(0, 0) = 12.0;
  A(0, 1) = 41.0;
  A(1, 0) = -756.0;
  A(1, 1) = -53.0;
  A(2, 0) = 31.0;
  A(2, 1) = -10.0;
  S21Matrix B(2, 3);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(0, 2) = 8.0;
  B(1, 0) = -9.0;
  B(1, 1) = 6.0;
  B(1, 2) = -5.0;
  A *= B;
  S21Matrix C(3, 3);
  C(0, 0) = -345.0;
  C(0, 1) = 258.0;
  C(0, 2) = -109.0;
  C(1, 0) = -1035.0;
  C(1, 1) = -1074.0;
  C(1, 2) = -5783.0;
  C(2, 0) = 152;
  C(2, 1) = -29;
  C(2, 2) = 298;
  bool res = A.EqMatrix(C);
  EXPECT_TRUE(res);
}