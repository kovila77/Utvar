#pragma once
#include "ElectricStove.h"
#include "Pan.h"
#include <string>

class Multicooker : virtual public Pan, virtual public ElectricStove
{
public:
	bool haveFastFunction;

	Multicooker();

	void print() override;

	std::string GetTypeName() override;
};