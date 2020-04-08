#include "Stove.h"
#include <iostream>
#include "Input.h"
#include <string>

Stove::Stove()
{
	std::cout << "Write Color: " << std::endl;
	while (true)
	{
		color = inputInt();
		if (color > 0)
		{
			break;
		}
		std::cout << "Color must be > 0" << std::endl;
	}
}

void Stove::print()
{
	KitchenUtensils::print();
	std::cout << "Color: " << color << std::endl;
}

std::string Stove::GetTypeName()
{
	return "Stove";
}