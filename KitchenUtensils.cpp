#include "KitchenUtensils.h"
#include <iostream>
#include <string>
#include "Input.h"

KitchenUtensils::KitchenUtensils()
{
	std::cout << "Создание утвари..." << std::endl;
	std::cout << "Введите инвентарный номер: "<< std::endl;
	inventoryNumber = inputInt();
}

void KitchenUtensils::print()
{
	std::cout << "Инвентарный номер: " << inventoryNumber << std::endl;
}