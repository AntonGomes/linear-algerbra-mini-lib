#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>

class Matrix {
public:
    Matrix(int rows, int cols);

    int getNumRows() const;
    int getNumCols() const;
    double get(int i, int j) const;

    void set(int row, int col, double val);

    Matrix add(const Matrix& other) const;
    Matrix dot(const Matrix& other) const;
    Matrix transpose() const;

    bool isUpperTriangular() const;
    bool isLowerTriangular() const;

    void print() const;
private:
    int numRows;
    int numCols;
    bool isSquare;
    std::vector<std::vector<double>> data;
};