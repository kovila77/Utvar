#include "Stove.h"
#include <iostream>

Stove::Stove()
{
	std::cout << "Write Color: " << color << std::endl;
}

void Stove::print()
{
	KitchenUtensils::print();
	std::cout << "Color: " << color << std::endl;
}