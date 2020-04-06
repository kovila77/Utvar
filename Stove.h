#pragma once
#include "KitchenUtensils.h"

class Stove : virtual public KitchenUtensils
{
public:
	unsigned int color;

	Stove();
	
	void print()  override;
};