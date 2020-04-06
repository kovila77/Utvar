#include "Pan.h"
#include <iostream>

Pan::Pan(int volume, int inventoryNumber)
{
	this->volume = volume;
	this->inventoryNumber = inventoryNumber;
}

void Pan::print()
{
	KitchenUtensils::print();
	std::cout << "Volume: " << volume << std::endl;
}