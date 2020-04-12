#pragma once
#include <string>
#include "Stove.h"

class GasStove : virtual public Stove
{
public:
	int gasConsumption;

	GasStove(int inventoryNumber, string color, int gasConsumption);

	void print() override;

	std::string GetTypeName() override;

	~GasStove() override = default;

};