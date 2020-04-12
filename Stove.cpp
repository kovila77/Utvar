#include <iostream>
#include <string>
#include "Stove.h"
#include "Input.h"
#include "Tree.h"

Stove::Stove(int inventoryNumber, string color) : KitchenUtensils(inventoryNumber)
{
	this->color = color;
}

void Stove::print()
{
	KitchenUtensils::print();
	std::cout << "����: " << color << std::endl;
}

std::string Stove::GetTypeName()
{
	return "�����";
}