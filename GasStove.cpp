#include <iostream>
#include <string>
#include "GasStove.h"
#include "Input.h"
#include "Tree.h"

GasStove::GasStove(int inventoryNumber, string color, int gasConsumption) : KitchenUtensils(inventoryNumber), Stove(inventoryNumber, color)
{
	this->gasConsumption = gasConsumption;
}

void GasStove::print()
{
	Stove::print();
	std::cout << "Потребление газа: " << gasConsumption << std::endl;
}

std::string GasStove::GetTypeName()
{
	return "Газовая плита";
}