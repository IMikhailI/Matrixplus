#include "../s21_matrix_oop.h"

S21Matrix ::S21Matrix() {
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::invalid_argument("ERROR");
  } else {
    this->matrix_ = new double *[rows]();
    for (int i = 0; i < rows; i++) {
      this->matrix_[i] = new double[cols]();
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  if (other.matrix_ == nullptr) {
    throw std::invalid_argument("ERROR");
  }
  this->matrix_ = new double *[rows_];
  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[cols_];
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  if (this->matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
    this->matrix_ = nullptr;
    this->rows_ = 0;
    this->cols_ = 0;
  }
}
