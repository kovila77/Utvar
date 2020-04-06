#pragma once
#include "Stove.h"

class ElectricStove : public Stove
{
public:
	int power;

	ElectricStove();

	void print()  override;
};