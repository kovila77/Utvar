#include "Stove.h"
#include <iostream>
#include "Input.h"
#include <string>

Stove::Stove()
{
	std::cout << "¬ведите цвет: " << std::endl;
	while (true)
	{
		color = inputInt();
		if (color > 0)
		{
			break;
		}
		std::cout << "÷вет должен быть > 0" << std::endl;
	}
}

void Stove::print()
{
	KitchenUtensils::print();
	std::cout << "÷вет: " << color << std::endl;
}

std::string Stove::GetTypeName()
{
	return "ѕлита";
}