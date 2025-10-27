#include<iostream> 

#include <SDL3/SDL.h>
#include "SDLWrapper.h"

int main()
{
	std::cout << "herro?\n";

	int screenWidth = 500; 
	int screenHeight = 500; 

	SDLWrapper sdlWrapper(screenWidth, screenHeight);

	return sdlWrapper.run(); 
}