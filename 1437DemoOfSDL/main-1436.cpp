#include<array> 
#include<iostream> 

#include <SDL3/SDL.h>
#include "SDLWrapper.h"


#include"Color.h"






int main()
{

	std::cout << cos(90) << "\n"; //is it zero? (no, C++ trig funcs use radians)

	std::cout << sizeof(int) << "\n";

	int a = 2; 

	int screenWidth = 1000; 
	int screenHeight = 1000; 

	SDLWrapper sdlWrapper(screenWidth, screenHeight);

	return sdlWrapper.run(); 
}