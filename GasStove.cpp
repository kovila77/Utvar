#include "GasStove.h"
#include <iostream>
#include <string>
#include "Input.h"

GasStove::GasStove()
{
	std::cout << "Write Gas consumption: "<< std::endl;
	gasConsumption = inputInt();
}

void GasStove::print()
{
	Stove::print();
	std::cout << "Gas consumption: " << gasConsumption << std::endl;
}

std::string GasStove::GetTypeName()
{
	return "GasStove";
}