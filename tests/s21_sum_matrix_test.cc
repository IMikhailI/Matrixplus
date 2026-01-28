#include "s21_test.h"

TEST(SumTest, CorrectSum_1) {
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
  S21Matrix C(2, 2);
  C(0, 0) = 4.0;
  C(0, 1) = 2.0;
  C(1, 0) = 0.0;
  C(1, 1) = 12.0;
  EXPECT_TRUE((A + B).EqMatrix(C));
}
TEST(SumTest, CorrectSum_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 12.0;
  A(0, 1) = 41.0;
  A(1, 0) = -756.0;
  A(1, 1) = -53.0;
  S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = -9.0;
  B(1, 1) = 6.0;
  A += B;
  S21Matrix C(2, 2);
  C(0, 0) = 14.0;
  C(0, 1) = 42.0;
  C(1, 0) = -765.0;
  C(1, 1) = -47.0;
  EXPECT_TRUE(A.EqMatrix(C));
}
TEST(SumTest, IncorrectSum_1) {
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
  EXPECT_THROW(A += B, std::invalid_argument);
}
TEST(SumTest, IncorrectSum_2) {
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
  S21Matrix B(2, 2);
  B(0, 0) = 2.0;
  B(0, 1) = 1.0;
  B(1, 0) = -9.0;
  B(1, 1) = 6.0;
  EXPECT_THROW(A += B, std::invalid_argument);
}
