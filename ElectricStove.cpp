#include "ElectricStove.h"
#include <iostream>
#include <string>
#include "Input.h"

ElectricStove::ElectricStove()
{
	std::cout << "������� ��������: " << std::endl;
	power = inputInt();
}

void ElectricStove::print()
{
	Stove::print();
	std::cout << "��������: " << power << std::endl;
}

std::string ElectricStove::GetTypeName()
{
	return "������������� �����";
}