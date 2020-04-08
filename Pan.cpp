#include "Pan.h"
#include <iostream>
#include <string>
#include "Input.h"

Pan::Pan()
{
	std::cout << "Write Volume: " << std::endl;
	volume = inputInt();
}

void Pan::print()
{
	KitchenUtensils::print();
	std::cout << "Volume: " << volume << std::endl;
}

std::string Pan::GetTypeName()
{
	return "Pan";
}