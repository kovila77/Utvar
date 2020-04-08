#include "ElectricStove.h"
#include <iostream>
#include <string>
#include "Input.h"

ElectricStove::ElectricStove()
{
	std::cout << "Введите мощность: " << std::endl;
	power = inputInt();
}

void ElectricStove::print()
{
	Stove::print();
	std::cout << "Мощность: " << power << std::endl;
}

std::string ElectricStove::GetTypeName()
{
	return "Электрическая плита";
}