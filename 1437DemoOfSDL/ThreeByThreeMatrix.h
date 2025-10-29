#pragma once
#include<array> 

class ThreeByThreeMatrix
{
	std::array<std::array<float, 3>, 3> theMatrix;
public: 
	ThreeByThreeMatrix() = default; 
	ThreeByThreeMatrix(const std::array<std::array<float, 3>, 3> theMatrix);
	
	static ThreeByThreeMatrix rotate(float xRadians, float yRadians);

	ThreeByThreeMatrix operator * (const ThreeByThreeMatrix& rhs)
	{
		ThreeByThreeMatrix theProduct; 



		return theProduct; 
	}
};

//not to be confused with std::vector<std::vector<>>
class TwoDVector
{
	float x, y; 

public: 
	TwoDVector() = delete; 
	TwoDVector(int x, int y); 
};

