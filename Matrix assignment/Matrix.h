#pragma once
class Matrix
{
private:
	int x11{}, x12{}, x21{}, x22{};

public: 
	
	Matrix() = default; //this will initialize all 4 integers to 0; 
	Matrix(int x11, int x12, int x21, int x22);

	Matrix operator + (const Matrix& matrixOnTheRight);

	void print(); 

};

