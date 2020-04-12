#include <iostream>
#include <string>
#include "KitchenUtensils.h"
#include "Input.h"

KitchenUtensils::KitchenUtensils(int inventoryNumber)
{
	this->inventoryNumber = inventoryNumber;
}

void KitchenUtensils::print()
{
	std::cout << "Инвентарный номер------------------> " << inventoryNumber << std::endl;
}