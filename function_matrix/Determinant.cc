#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (this->cols_ != this->rows_) {
    throw std::invalid_argument("--Matrix is not square--");
  }
  int count_row = this->rows_;
  int flag = 0;
  double det = 1.0;
  S21Matrix tmp(*this);
  for (int i = 0; i < count_row && flag == 0; i++) {
    int max_row = i;
    for (int k = i + 1; k < count_row; k++) {
      if (fabs(tmp.matrix_[k][i]) > fabs(tmp.matrix_[max_row][i])) {
        max_row = k;
      }
    }
    if (max_row != i) {
      for (int j = i; j < count_row; j++) {
        double temp = tmp.matrix_[i][j];
        tmp.matrix_[i][j] = tmp.matrix_[max_row][j];
        tmp.matrix_[max_row][j] = temp;
      }
      det *= -1;
    }
    if (fabs(tmp.matrix_[i][i]) < 1e-7) {
      flag = 1;
      break;
    }
    for (int k = i + 1; k < count_row; k++) {
      double factor = tmp.matrix_[k][i] / tmp.matrix_[i][i];
      for (int j = i; j < count_row; j++) {
        tmp.matrix_[k][j] -= factor * tmp.matrix_[i][j];
      }
    }
  }
  if (flag == 0) {
    for (int i = 0; i < count_row; i++) {
      det *= tmp.matrix_[i][i];
    }
  } else {
    det = 0.0;
  }
  return det;
}
