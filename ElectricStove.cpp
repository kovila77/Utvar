#include "ElectricStove.h"
#include <iostream>

ElectricStove::ElectricStove()
{
	std::cout << "Write Power: " << power << std::endl;
}

void ElectricStove::print()
{
	Stove::print();
	std::cout << "Power: " << power << std::endl;
}