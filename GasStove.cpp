#include "GasStove.h"
#include <iostream>
#include <string>
#include "Input.h"

GasStove::GasStove()
{
	std::cout << "Введите сколько газа потребляет: "<< std::endl;
	gasConsumption = inputInt();
}

void GasStove::print()
{
	Stove::print();
	std::cout << "Потребление газа: " << gasConsumption << std::endl;
}

std::string GasStove::GetTypeName()
{
	return "Газовая плита";
}