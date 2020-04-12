#pragma once
#include <string>
#include "KitchenUtensils.h"
using namespace std;

class Stove : virtual public KitchenUtensils
{
public:
	string color;

	Stove(int inventoryNumber, string color);

	void print()  override;

	std::string GetTypeName() override;

	~Stove() override = default;
};