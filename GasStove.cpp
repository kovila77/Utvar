#include "GasStove.h"
#include <iostream>

GasStove::GasStove(int gasConsumption, unsigned int color, int inventoryNumber) : Stove (color, inventoryNumber)
{
	this->gasConsumption = gasConsumption;
}

void GasStove::print()
{
	Stove::print();
	std::cout << "Gas consumption: " << gasConsumption << std::endl;
}