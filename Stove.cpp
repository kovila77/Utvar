#include "Stove.h"
#include <iostream>
#include "Input.h"
#include <string>

Stove::Stove()
{
	std::cout << "������� ����: " << std::endl;
	while (true)
	{
		color = inputInt();
		if (color > 0)
		{
			break;
		}
		std::cout << "���� ������ ���� > 0" << std::endl;
	}
}

void Stove::print()
{
	KitchenUtensils::print();
	std::cout << "����: " << color << std::endl;
}

std::string Stove::GetTypeName()
{
	return "�����";
}