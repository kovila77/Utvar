#include <iostream>
#include <string>
#include "Multicooker.h"
#include "Input.h"
#include "Tree.h"

Multicooker::Multicooker(int inventoryNumber, string color, int power, int volume, bool haveFastFunction)
	: KitchenUtensils(inventoryNumber), ElectricStove(inventoryNumber, color, power), Pan(inventoryNumber, volume), Stove(inventoryNumber, color)
{
	this->haveFastFunction = haveFastFunction;
}

void Multicooker::print()
{
	ElectricStove::print();
	std::cout << "Объём: " << volume << std::endl;
	std::cout << "Имеется функция скороварки: " << (haveFastFunction ? "yes" : "no") << std::endl;
}

std::string Multicooker::GetTypeName()
{
	return "Мультиварка";
}