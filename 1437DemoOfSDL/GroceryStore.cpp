#include "GroceryStore.h"

Customer::Customer(const std::string& name, size_t itemCount)
	:name(name), itemCount(itemCount)
{

}

size_t Customer::getItemCount()
{
	return itemCount; 
}

size_t CheckoutLane::estimateTheWaitTime()
{
	
	size_t scanTimePerItem = 1; //second

	//if (isSeniorCitizenWithCouponsInLine) scanTimePerItem *= 4; 
	
	//copy lane contents so you don't modify the original (and empty the queue): 
	auto copyOfThisLane = lane; 

	size_t totalItems = 0; 
	while (!copyOfThisLane.empty())
	{
		totalItems += copyOfThisLane.front().getItemCount(); 
		copyOfThisLane.pop_front(); 
	}


	return totalItems;
}

void GroceryStore::addCustomer(const std::string& customerName)
{

}

bool GroceryStore::checkForPopBack()
{
	return false;
}
