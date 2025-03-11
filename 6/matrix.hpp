#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows, cols;

public:
    Matrix(int rows, int cols);
    void randomFill(int min, int max);
    void print() const;
    static Matrix multiply(const Matrix &A, const Matrix &B, int numThreads);
};

#endif
