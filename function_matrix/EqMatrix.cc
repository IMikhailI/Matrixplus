#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs((*this)(i, j) - other(i, j)) > 1e-7) {
        return false;
      }
    }
  }

  return true;
}
