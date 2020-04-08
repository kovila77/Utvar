#pragma once
#include "Stove.h"
#include <string>

class ElectricStove : public Stove
{
public:
	int power;

	ElectricStove();

	void print()  override;

	std::string GetTypeName() override;
};