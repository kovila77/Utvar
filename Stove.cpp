#include "Stove.h"
#include <iostream>

Stove::Stove(unsigned int color, int inventoryNumber)
{
	this->color = color;
	this->inventoryNumber = inventoryNumber;
}

void Stove::print()
{
	std::cout << "Color: " << color << std::endl;
	KitchenUtensils::print();
}