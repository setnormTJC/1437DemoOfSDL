// Matrix assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"

void printThing(std::string someString)
{
	std::cout << someString << "\n";
}

int main()
{

	int someNumber = 122'234; 
	int copyOfSomeNumber = someNumber; 

	std::cout.imbue(std::locale(""));

	std::cout << someNumber << "\n";

	int numberOfDigitsInSomeNumber{};


	while (someNumber > 0)
	{
		someNumber = someNumber / 10; 
		numberOfDigitsInSomeNumber++; 

		std::cout << "Some number is NOW become: " << someNumber << "\n";
	}

	std::cout << "Some number: " << copyOfSomeNumber << " has this many digits: " << numberOfDigitsInSomeNumber << "\n";


	Matrix matrixA(758833294, 2, 3, 4);

	Matrix matrixB(5, 6, 7, 8);


	Matrix sum = matrixA.operator+(matrixB);


	//printf(sum); 

	sum.print(); 

	//std::cout << sum << "\n";

}

