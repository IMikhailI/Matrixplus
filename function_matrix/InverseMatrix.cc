#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix is not square");
  }

  double det = Determinant();
  if (fabs(det) < EPS) {
    throw std::invalid_argument("Matrix determinant is 0");
  }

  S21Matrix result(1, 1);
  double determinant = Determinant();
  if (rows_ == 1) {
    result.matrix_[0][0] = 1 / matrix_[0][0];
  } else {
    result = CalcComplements();
    result = result.Transpose();
    result *= (1.0 / determinant);
  }

  return result;
}
