#pragma once

#include<array>
#include <deque>
#include <string>
#include <map>

class Customer
{
	std::string name; 
	size_t itemCount{}; //just the total period (2 cartons of eggs, 1 banana, 4 tuna cans means this will be 7)
	//std::map<std::string, int> itemsToCounts = 
	//{
	//	"loaf of bread", 2
	//}

public: 
	Customer() = delete; //no empty strings for names, no customer can have 0 items 
	Customer(const std::string& name, size_t itemCount);

	size_t getItemCount();
};

class CheckoutLane
{
	/*we are using a DOUBLE-ended queue rather than single because what if somebody gets impatient*/
	std::deque<Customer> lane; 
	
public: 
	/*What people do: approximate the total number of items of everybody already in line*/
	size_t estimateTheWaitTime();


};

class GroceryStore
{
	//Let's say the grocery store is fairly small and only has 2 checkout lanes:
	std::array<CheckoutLane, 2> checkoutLanes; 

	/*each customer likely checks out which line is shorter*/
	void addCustomer(const std::string& customerName);

	/*presumably the last person leaves (pop_back) because the other line is shorter
	* OR the person may have forgotten to pick up some item on Aisle 5
	*/
	bool checkForPopBack();
};


