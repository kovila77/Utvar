#pragma once
#include "KitchenUtensils.h"
#include <string>

class Pan : virtual public KitchenUtensils
{
public:
	int volume;

	Pan();

	void print() override;

	std::string GetTypeName() override;
};