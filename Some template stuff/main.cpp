// Some template stuff.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<array> //static (size CANNOT change) 
#include <iostream>

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


//void printListOfNumbers(std::vector <int> listOfNumbers)
//{
//    for (const auto& num : listOfNumbers)
//    {
//        std::cout << num << "\n";
//
//    }
//}
//
//void printListOfStrings(const std::vector<std::string>& strings)
//{
//    for (const auto& currentString : strings) //DRY
//    {
//        std::cout << currentString << "\n";
//    }
//}

int main()
{

    int nums[5] = { 1, 2, 3, 4, 5};

    std::array<std::string, 3> names =
    {
        {"Alice", "Bob", "Carol"}
    };

    //std::vector nums = { 1, 2, 3 }; 
    CustomStaticArray<std::string, 4>  customStaticArray("Bobbo"); //calls default constructor
    
    int a = 123; 

    
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
