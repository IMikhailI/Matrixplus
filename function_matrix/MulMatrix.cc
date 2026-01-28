#include "../s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (rows_ != other.cols_ || cols_ != other.rows_ ||
      this->matrix_ == nullptr || other.matrix_ == nullptr) {
    throw std::invalid_argument("ERROR");
  }

  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      double temp = 0.0;
      for (int k = 0; k < this->cols_; k++) {
        temp += this->matrix_[i][k] * other.matrix_[k][j];
      }
      result.matrix_[i][j] = temp;
    }
  }
  *this = result;
}
