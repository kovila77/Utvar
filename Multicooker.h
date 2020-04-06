#pragma once
#include "ElectricStove.h"
#include "Pan.h"

class Multicooker : virtual public Pan, virtual public ElectricStove
{
public:
	bool haveFastFunction;

	Multicooker();

	void print() override;
};