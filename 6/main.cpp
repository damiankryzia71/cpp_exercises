#include "matrix.hpp"

#include <iostream>

int main()
{
    Matrix m1(2, 2);
    m1.randomFill(0, 9);
    m1.print();
    std::cout << std::endl;

    Matrix m2(2, 2);
    m2.randomFill(0, 9);
    m2.print();
    std::cout << std::endl;
    
    Matrix result = Matrix::multiply(m1, m2, 2); 
    result.print();

    return 0;
}