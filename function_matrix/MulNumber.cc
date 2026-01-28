#include "../s21_matrix_oop.h"

void S21Matrix::MulNumber(const double num) {
  if (this->matrix_ == nullptr) {
    throw std::invalid_argument("ERROR");
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}
