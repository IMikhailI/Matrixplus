#include "s21_test.h"

TEST(Determinant, CorrectMatrix_1) {
  S21Matrix C(3, 3);
  C(0, 0) = -345.0;
  C(0, 1) = 258.0;
  C(0, 2) = -109.0;
  C(1, 0) = -1035.0;
  C(1, 1) = -1074.0;
  C(1, 2) = -5783.0;
  C(2, 0) = 152;
  C(2, 1) = -29;
  C(2, 2) = -298;
  EXPECT_DOUBLE_EQ(C.Determinant(), -379985760);
}
TEST(Determinant, CorrectMatrix_2) {
  S21Matrix C(3, 3);
  C(0, 0) = 1.0;
  C(0, 1) = 1.0;
  C(0, 2) = 1.0;
  C(1, 0) = 1.0;
  C(1, 1) = 1.0;
  C(1, 2) = 1.0;
  C(2, 0) = 1.0;
  C(2, 1) = 1.0;
  C(2, 2) = 1.0;
  EXPECT_DOUBLE_EQ(C.Determinant(), 0.0);
}