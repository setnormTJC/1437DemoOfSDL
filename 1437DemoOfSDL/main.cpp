#include<iostream> 

#include <SDL3/SDL.h>
#include "SDLWrapper.h"

#include"Color.h"

struct Person
{
	int age;
	int height; //in inches (ft inches) 
	std::string eyeColor;
};


int main()
{

	//...
	Person me = { 37, 69, "blue" };
	std::cout << me.eyeColor << "\n";

	//std::cout << "herro?\n";

	Color someColor = { 1, 0, 255, 255 };



	std::cout << "The RED component of the someColor is: "
		<< someColor.r << "\n";

	std::cout << "Hello world\n";


	int screenWidth = 1000; 
	int screenHeight = 1000; 

	SDLWrapper sdlWrapper(screenWidth, screenHeight);

	return sdlWrapper.run(); 
}