#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (this->cols_ != this->rows_) {
    throw std::invalid_argument("--Matrix is not square--");
  }

  double determinant = Determinant();
  S21Matrix result(rows_, cols_);
  S21Matrix tmp_cofactor(1, 1);
  if (rows_ == 1) {
    result.matrix_[0][0] = determinant;
  } else {
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) {
        tmp_cofactor = Minor(i, j);
        determinant = tmp_cofactor.Determinant();
        result.matrix_[i][j] = pow(-1, i + j) * determinant;
      }
  }
  return result;
}
