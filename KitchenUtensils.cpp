#include "KitchenUtensils.h"
#include <iostream>

KitchenUtensils::KitchenUtensils()
{
	std::cout << "Write Invenory number: " << inventoryNumber << std::endl;
}

void KitchenUtensils::print()
{
	std::cout << "Invenory number: " << inventoryNumber << std::endl;
}