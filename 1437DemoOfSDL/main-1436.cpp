#include<array> 
#include<iostream> 

#include <SDL3/SDL.h>
#include "SDLWrapper.h"


#include"Color.h"

struct Building
{
	int numberOfRooms{}; 
	int height{}; 

};

struct/*(ure)*/ Person
{
	int age{};
	float bmi{}; 
	std::string eyeColor; 
	int height{}; 


	void print() //a "member function" (because it is a MEMBER of the Person structure ... and it's a function!
	{
		std::cout << age << "\t" << bmi << "\t" << eyeColor << "\n";
	}

	void jump(int howHigh)
	{
		height = height + howHigh; 

		std::cout << "After jumping, height temporarily increased to: " << height << "\n";
	}


};



void printThing()
{
	std::cout << "Thing\n";
}

int main()
{
	printThing(); 

	std::string word = "alpha";
	std::cout << word.length()<< "\n";


	Person me = { 37, 20.1, "the LOVELIEST blue", 69 };
	Person thee = { 21, 20.2, "hazel", 71 };


	//std::cout << me << "\n"; //we will fix this next semester (in the OOP)

	me.print(); 
	thee.print(); 

	me.jump(25); 



	int screenWidth = 1000; 
	int screenHeight = 1000; 


	SDLWrapper sdlWrapper(screenWidth, screenHeight);

	return sdlWrapper.run(); 
}