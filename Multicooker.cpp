#include "Multicooker.h"
#include <iostream>

Multicooker::Multicooker(bool haveFastFunction, int volume, int power, unsigned int color, int inventoryNumber) : ElectricStove(power, color, inventoryNumber), Pan(volume, inventoryNumber)
{
	this->haveFastFunction = haveFastFunction;
}

void Multicooker::print()
{
	std::cout << "Have fast function: " << (haveFastFunction ? "yes" : "no") << std::endl;

}