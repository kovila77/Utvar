#include "Multicooker.h"
#include <iostream>
#include <string>
#include "Input.h"

Multicooker::Multicooker()
{
	std::cout << "���� �� ������� ����������? (y, � / n, �): " << std::endl;
	haveFastFunction = inputBool();
}

void Multicooker::print()
{
	ElectricStove::print();
	std::cout << "�����: " << volume << std::endl;
	std::cout << "������� ������� ����������: " << (haveFastFunction ? "yes" : "no") << std::endl;
}

std::string Multicooker::GetTypeName()
{
	return "�����������";
}