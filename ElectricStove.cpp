#include <iostream>
#include <string>
#include "ElectricStove.h"
#include "Input.h"
#include "Tree.h"

ElectricStove::ElectricStove(int inventoryNumber, string color, int power) : KitchenUtensils(inventoryNumber), Stove(inventoryNumber, color)
{
	this->power = power;
}

void ElectricStove::print()
{
	Stove::print();
	std::cout << "��������: " << power << std::endl;
}

std::string ElectricStove::GetTypeName()
{
	return "������������� �����";
}