#include "ThreeByThreeMatrix.h"

#include<algorithm>
#include<cmath>

TwoDVector::TwoDVector(int x, int y)
	:x(x), y(y)
{

}

ThreeByThreeMatrix::ThreeByThreeMatrix(const std::array<std::array<float, 3>, 3> theMatrix)
    :theMatrix(theMatrix)
{

}

ThreeByThreeMatrix ThreeByThreeMatrix::rotate(float xRadians, float yRadians)
{
    float cx = std::cos(xRadians);
    float sx = std::sin(xRadians);
    float cy = std::cos(yRadians);
    float sy = std::sin(yRadians);

    std::array<std::array<float, 3>, 3> arrX =  
    { {
        {1.0f,  0.0f,   0.0f},
        {0,     cx,     -sx },
        {0,     sx,     cx}
    } };

    ThreeByThreeMatrix rotX = arrX;

    std::array<std::array<float, 3>, 3> arrY =
    { {
        {cy,  0,  sy},
        {0,   1,  0 },
        {-sy, 0,  cy}
    } };

    ThreeByThreeMatrix rotY = arrY; 
    
    return rotY * rotX; // rotate X first, then Y
}

