#include "Pan.h"
#include <iostream>

Pan::Pan()
{
	std::cout << "Write Volume: " << volume << std::endl;
}

void Pan::print()
{
	KitchenUtensils::print();
	std::cout << "Volume: " << volume << std::endl;
}