#include <iostream>
#include <string>
#include "Pan.h"
#include "Input.h"
#include "Tree.h"

Pan::Pan(int inventoryNumber, int volume) : KitchenUtensils(inventoryNumber)
{
	this->volume = volume;
}

void Pan::print()
{
	KitchenUtensils::print();
	std::cout << "Îáú¸ì: " << volume << std::endl;
}

std::string Pan::GetTypeName()
{
	return "Êàñòðþëÿ";
}