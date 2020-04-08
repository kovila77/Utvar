#include "GasStove.h"
#include <iostream>
#include <string>
#include "Input.h"

GasStove::GasStove()
{
	std::cout << "������� ������� ���� ����������: "<< std::endl;
	gasConsumption = inputInt();
}

void GasStove::print()
{
	Stove::print();
	std::cout << "����������� ����: " << gasConsumption << std::endl;
}

std::string GasStove::GetTypeName()
{
	return "������� �����";
}