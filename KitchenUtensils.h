#pragma once
#include <string>

class KitchenUtensils
{
public:
	int inventoryNumber;

	virtual void print() = 0;

	virtual std::string GetTypeName() = 0;

protected:
	KitchenUtensils();
};