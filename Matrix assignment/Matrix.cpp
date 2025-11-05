#include "Matrix.h"

#include<iomanip> 
#include <iostream>


Matrix::Matrix(int x11, int x12, int x21, int x22)
	:x11(x11), x12(x12), x21(x21), x22(x22)
{

}

Matrix Matrix::operator+(const Matrix& matrixOnTheRight)
{
	Matrix theSum; 

	int copy = this->x11; 

	theSum.x11 = this->x11 + matrixOnTheRight.x11; 

	theSum.x12 = this->x12 + matrixOnTheRight.x12; //x sub 1, 2; t sub 0

	return theSum; 
}

void Matrix::print()
{

	const int COLUMN_WIDTH = 10; 

	std::cout << std::left << std::setw(COLUMN_WIDTH) << x11;
	std::cout << std::left << std::setw(COLUMN_WIDTH) << x12; 
	std::cout << "\n";

	std::cout << std::left << std::setw(COLUMN_WIDTH) << x21; 	
	std::cout << std::left << std::setw(COLUMN_WIDTH) << x22 << "\n";
}
