#include "Multicooker.h"
#include <iostream>
#include <string>
#include "Input.h"

Multicooker::Multicooker()
{
	std::cout << "Есть ли функция скороварки? (y, д / n, н): " << std::endl;
	haveFastFunction = inputBool();
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