#include "ElectricStove.h"
#include <iostream>
#include <string>
#include "Input.h"

ElectricStove::ElectricStove()
{
	std::cout << "Write Power: " << std::endl;
	power = inputInt();
}

void ElectricStove::print()
{
	Stove::print();
	std::cout << "Power: " << power << std::endl;
}

std::string ElectricStove::GetTypeName()
{
	return "ElectricStove";
}