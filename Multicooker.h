#pragma once
#include "ElectricStove.h"
#include "Pan.h"

class Multicooker : virtual public Pan, virtual public ElectricStove
{
public:
	bool haveFastFunction;

	Multicooker(bool haveFastFunction, int volume, int power, unsigned int color, int inventoryNumber);

	void print() override;
};