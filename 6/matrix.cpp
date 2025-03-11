#include "matrix.hpp"

#include <iostream>
#include <random>
#include <thread>

Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    data = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
}

void Matrix::randomFill(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = dist(gen); 
        }
    }
}

void Matrix::print() const
{
    for (int i = 0; i < rows; i++)
    {
        std::cout << "[";
        for (int j = 0; j < cols; j++)
        {
            if (j == cols - 1)
                std::cout << data[i][j] << "]" << std::endl;
            else    
                std::cout << data[i][j] << ", ";
        }
    }
}

void computeResult(std::vector<std::vector<int>>& resultMatrixData, 
    int startRow, int endRow, 
    int cols, int n, 
    const std::vector<std::vector<int>>& aData, 
    const std::vector<std::vector<int>>& bData)
{
    for (int i = startRow; i < endRow; i++)  
    {
        for (int j = 0; j < cols; j++)
        {
            int result = 0;
            for (int k = 0; k < n; k++)
                result += aData[i][k] * bData[k][j];

            resultMatrixData[i][j] = result;
        }
    }
}

Matrix Matrix::multiply(const Matrix &a, const Matrix &b, int numThreads)
{
    Matrix resultMatrix(a.rows, b.cols);
    int rowsPerThread = a.rows / numThreads;
    int remainder = a.rows % numThreads;

    std::vector<std::thread> threads;
    int startRow = 0;

    for (int i = 0; i < numThreads; i++)
    {
        int endRow = startRow + rowsPerThread + (i < remainder ? 1 : 0);

        threads.emplace_back(computeResult, std::ref(resultMatrix.data), startRow, endRow, 
                             resultMatrix.cols, a.cols, 
                             std::cref(a.data), std::cref(b.data));

        startRow = endRow;
    }

    for (auto& t : threads)
    {
        t.join();
    }

    return resultMatrix;
}

