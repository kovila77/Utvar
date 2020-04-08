#include "KitchenUtensils.h"
#include <iostream>
#include <string>
#include "Input.h"

KitchenUtensils::KitchenUtensils()
{
	std::cout << "—оздание утвари..." << std::endl;
	//std::cout << "¬ведите инвентарный номер: " << std::endl;
	std::cout << "¬ведите инвентарный номер: "<< std::endl;
	inventoryNumber = inputInt();
}

void KitchenUtensils::print()
{
	std::cout << "»нвентарный номер------------------> " << inventoryNumber << std::endl;
}