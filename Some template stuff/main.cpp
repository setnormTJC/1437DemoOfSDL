// Some template stuff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<array> //static (size CANNOT change) 
#include <iostream>
#include<exception>


#include<vector> //dynamic array (which can grow and shrink) 
#include "CustomStaticArray.h"

template<typename SomeDataType> 
void printThings(std::vector <SomeDataType> listOfThangs)
{
    for (const auto& thang : listOfThangs)
    {
        std::cout << thang << "\n";

    }
}

int main()
{
    try
    {
        constexpr int arrayMaxSize = 3; 
        std::array<std::string, arrayMaxSize> names =
        {
            {"Alice", "Bob", "Carol"}
        };

        //std::vector nums = { 1, 2, 3 }; 
        CustomStaticArray<std::string, 4>  customStaticArray("Bobbo"); //calls parameterized constructor

        //CustomStaticArray<int, 5> otherCustomStaticArray(1);

        int index = 1;
        std::cout << customStaticArray.operator[](index) << "\n";
        customStaticArray[0] = "Alice";
        customStaticArray[1] = "Bob";
        customStaticArray[2] = "Carol";
        //customStaticArray[3] = "Darth";

        std::cout << "After inserting Alice, Bob, Carol, the FRONT of the array contains: "
            << customStaticArray.getFront() << "\n";

        int a = 123;
    } //end of the "try block"

    catch (const std::exception& exception)
    {
        std::system("start https://youtu.be/mJZZNHekEQw?si=5lu_OcLkmEV7OCak&t=85");
        std::cout << exception.what() << "\n";
    }
    
    //=
    //{
    //    {"Alice", "Bob", "Carol"}
    //};

    //std::cout << names[100] << "\n"; //You cannot pass! (Gandalf reference) 

    //std::vector<int> nums = { 1, 2, 3, 4 };

    //std::vector<std::string> names =
    //{
    //    "Alice",
    //    "Bob",
    //    "Carol"
    //};

    //printListOfNumbers(nums); 
    //printListOfStrings(names); 


    //printThings(nums); 
    //printThings(names); 

}
