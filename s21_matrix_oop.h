#pragma once

#include <gtest/gtest.h>

#include <cmath>
#include <iostream>

#define EPS 1e-7

class S21Matrix {
 private:
  // attributes
  int rows_, cols_;
  double** matrix_;

 public:
  // constructors, destructor
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // getters
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // operators overloads
  S21Matrix operator+(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);
  S21Matrix& operator*=(const double num);
  S21Matrix& operator*=(const S21Matrix& other);
  double& operator()(int row, int col);
  const double& operator()(int row, int col) const;

  S21Matrix Minor(int row, int col);
  void SetRows(const int rows);
  void SetCols(const int cols);
  int GetRows();
  int GetCols();
};
