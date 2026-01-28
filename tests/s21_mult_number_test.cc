#include "s21_test.h"

TEST(MultNumTest, CorrectMultNum_1) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  S21Matrix C(2, 2);
  C(0, 0) = 4.0;
  C(0, 1) = 2.0;
  C(1, 0) = 18.0;
  C(1, 1) = 12.0;
  EXPECT_TRUE((A * 2.0).EqMatrix(C));
}
TEST(MultNumTest, CorrectMultNum_2) {
  S21Matrix A(2, 2);
  A(0, 0) = 2.0;
  A(0, 1) = 1.0;
  A(1, 0) = 9.0;
  A(1, 1) = 6.0;
  S21Matrix C(2, 2);
  C(0, 0) = 4.0;
  C(0, 1) = 2.0;
  C(1, 0) = 18.0;
  C(1, 1) = 12.0;
  EXPECT_TRUE((A * 2.0).EqMatrix(C));
}
TEST(MultNumTest, CorrectMultNum_3) {
  S21Matrix A(3, 2);
  A(0, 0) = 12.0;
  A(0, 1) = 41.0;
  A(1, 0) = -756.0;
  A(1, 1) = -53.0;
  A(2, 0) = 31.0;
  A(2, 1) = -10.0;

  A *= 2.0;
  S21Matrix C(3, 2);
  C(0, 0) = 24.0;
  C(0, 1) = 82.0;
  C(1, 0) = -1512.0;
  C(1, 1) = -106.0;
  C(2, 0) = 62.0;
  C(2, 1) = -20.0;

  EXPECT_TRUE(A == (C));
}
TEST(MultNumTest, IncorrectMultNum_1) {
  S21Matrix A;

  EXPECT_THROW(A *= 1, std::invalid_argument);
}
