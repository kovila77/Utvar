#include "KitchenUtensils.h"
#include <iostream>
#include <string>
#include "Input.h"

KitchenUtensils::KitchenUtensils()
{
	std::cout << "Write Invenory number: "<< std::endl;
	inventoryNumber = inputInt();
}

void KitchenUtensils::print()
{
	std::cout << "Invenory number: " << inventoryNumber << std::endl;
}