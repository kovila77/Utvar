#pragma once
#include "Stove.h"

class ElectricStove : virtual public Stove
{
public:
	int power;

	ElectricStove(int power, unsigned int color, int inventoryNumber);

	void print();
};