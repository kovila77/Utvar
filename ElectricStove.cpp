#include "ElectricStove.h"
#include <iostream>

ElectricStove::ElectricStove(int power, unsigned int color, int inventoryNumber) : Stove(color, inventoryNumber)
{
	this->power = power;
}

void ElectricStove::print()
{
	std::cout << "Power: " << power << std::endl;
	Stove::print();
}