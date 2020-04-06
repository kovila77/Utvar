#pragma once
#include "Stove.h"

class GasStove : virtual public Stove
{
public:
	int gasConsumption;

	GasStove(int gasConsumption, unsigned int color, int inventoryNumber);

	void print() override;
};