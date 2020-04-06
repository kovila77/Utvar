#include "GasStove.h"
#include <iostream>

GasStove::GasStove()
{
	std::cout << "Write Gas consumption: " << gasConsumption << std::endl;
}

void GasStove::print()
{
	Stove::print();
	std::cout << "Gas consumption: " << gasConsumption << std::endl;
}