#pragma once
#include <string>
#include "Stove.h"

class ElectricStove : virtual public Stove
{
public:
	int power;

	ElectricStove(int inventoryNumber, string color, int power);

	void print()  override;

	std::string GetTypeName() override;

	~ElectricStove() override = default;
};