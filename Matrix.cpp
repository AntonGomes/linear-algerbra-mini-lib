#include <iostream>
#include <vector>

class Matrix {
private:
  int m_rows;
  int m_cols;
  bool isSquare;
  std::vector<std::vector<double>> m_data;
public:
    // Constructor initialises zero matrix
    Matrix(int rows, int cols) : 
        m_rows(rows), 
        m_cols(cols), 
        isSquare(rows == cols),
        m_data(rows, std::vector<double>(cols)) {}

    int getNumRows() const { return m_rows; }
    int getNumCols() const { return m_cols; }

    double get(int i, int j) const { return m_data[i][j]; }
    void set(int i, int j, double value) { m_data[i][j] = value; }

    Matrix add(const Matrix& other) const {
        if (m_rows != other.getNumRows() || m_cols != other.getNumCols()) {
            throw std::invalid_argument("Matrices must have the same dimensions");
        }

        Matrix result(m_rows, m_cols);
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                result.set(i, j, get(i, j) + other.get(i, j));
            }
        }
        return result;
    }

    Matrix dot(const Matrix& other) const {
        if (m_cols != other.getNumRows()) {
            throw std::invalid_argument("Matrix dimensions do not match for multiplication");
        }

        Matrix result(m_rows, other.getNumCols());

        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < other.getNumCols(); j++) {
                double sum = 0.0;
                for (int k = 0; k < m_cols; k++) {
                    sum += get(i, k) * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result(m_cols, m_rows);
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                result.set(j, i, get(i, j));
            }
        }
        return result;
    }

    bool isUpperTriangular() const {
        if (!isSquare) {
            return false;
        }

        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < i; j++) {
                if (get(i, j) != 0.0) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isLowerTriangular() const {
        if (!isSquare) {
            return false;
        }

        for (int i = 0; i < m_rows; i++) {
            for (int j = i + 1; j < m_cols; j++) {
                if (get(i, j) != 0.0) {
                    return false;
                }
            }
        }
        return true;
    }

    void print() const {
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                std::cout << get(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
  
};