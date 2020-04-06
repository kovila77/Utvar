#pragma once
#include "Stove.h"

class ElectricStove : public Stove
{
public:
	int power;

	ElectricStove(int power, unsigned int color, int inventoryNumber);

	void print()  override;
};