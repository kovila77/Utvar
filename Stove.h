#pragma once
#include "KitchenUtensils.h"
#include <string>

class Stove : virtual public KitchenUtensils
{
public:
	unsigned int color;

	Stove();

	void print()  override;

	std::string GetTypeName() override;

	~Stove() override = default;
};