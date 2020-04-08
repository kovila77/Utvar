#include "Multicooker.h"
#include <iostream>
#include <string>
#include "Input.h"

Multicooker::Multicooker()
{
	std::cout << "Write Have fast function: " << std::endl;
	haveFastFunction = inputBool();
}

void Multicooker::print()
{
	ElectricStove::print();
	std::cout << "Volume: " << volume << std::endl;
	std::cout << "Have fast function: " << (haveFastFunction ? "yes" : "no") << std::endl;
}

std::string Multicooker::GetTypeName()
{
	return "Multicooker";
}