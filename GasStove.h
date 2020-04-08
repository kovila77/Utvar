#pragma once
#include "Stove.h"
#include <string>

class GasStove : virtual public Stove
{
public:
	int gasConsumption;

	GasStove();

	void print() override;

	std::string GetTypeName() override;

	~GasStove() override = default;

};