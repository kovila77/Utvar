#include "Multicooker.h"
#include <iostream>

Multicooker::Multicooker()
{
	std::cout << "Write Have fast function: " << (haveFastFunction ? "yes" : "no") << std::endl;
}

void Multicooker::print()
{
	ElectricStove::print();
	std::cout << "Volume: " << volume << std::endl;
	std::cout << "Have fast function: " << (haveFastFunction ? "yes" : "no") << std::endl;
}