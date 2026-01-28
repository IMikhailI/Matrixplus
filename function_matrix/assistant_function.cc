#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::Minor(int row, int col) {
  S21Matrix result(rows_ - 1, cols_ - 1);
  int i = 0, j = 0;
  for (int m = 0; m < rows_; m++)
    for (int n = 0; n < cols_; n++)
      if (m != row && n != col) {
        result.matrix_[i][j] = matrix_[m][n];
        j++;
        if (j == rows_ - 1) {
          j = 0;
          i++;
        }
      }
  return result;
}

void S21Matrix::SetRows(const int rows) {
  if (rows < 1) {
    throw std::invalid_argument("ERROR");
  }
  S21Matrix result(rows, cols_);
  for (size_t i = 0; i < (size_t)rows; ++i) {
    for (size_t j = 0; j < (size_t)cols_; ++j) {
      if (i < (size_t)rows_) {
        result.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = result;
}

void S21Matrix::SetCols(const int cols) {
  if (cols <= 0) {
    throw std::invalid_argument("ERROR");
  }
  S21Matrix result(rows_, cols);
  for (size_t i = 0; i < (size_t)rows_; ++i) {
    for (size_t j = 0; j < (size_t)cols; ++j) {
      if (j < (size_t)cols_) {
        result.matrix_[i][j] = matrix_[i][j];
      }
    }
  }
  *this = result;
}

int S21Matrix::GetRows() { return rows_; }
int S21Matrix::GetCols() { return cols_; }