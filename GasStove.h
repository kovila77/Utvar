#pragma once
#include "Stove.h"

class GasStove : virtual public Stove
{
public:
	int gasConsumption;

	GasStove();

	void print() override;
};