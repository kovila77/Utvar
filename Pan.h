#pragma once
#include "KitchenUtensils.h"

class Pan : virtual public KitchenUtensils
{
public:
	int volume;

	Pan();

	void print() override;
};