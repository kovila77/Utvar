#pragma once
#include "KitchenUtensils.h"

class Stove : virtual public KitchenUtensils
{
public:
	unsigned int color;

	Stove(unsigned int color, int inventoryNumber);

	Stove() = delete;
	
	void print();
};