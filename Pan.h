#pragma once
#include <string>
#include "KitchenUtensils.h"

class Pan : virtual public KitchenUtensils
{
public:
	int volume;

	Pan(int inventoryNumber, int volume);

	void print() override;

	std::string GetTypeName() override;

	~Pan() override = default;
};