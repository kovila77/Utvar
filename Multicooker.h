#pragma once
#include <string>
#include "ElectricStove.h"
#include "Pan.h"

class Multicooker : virtual public Pan, virtual public ElectricStove
{
public:
	bool haveFastFunction;

	Multicooker(int inventoryNumber, string color, int power, int volume, bool haveFastFunction);

	void print() override;

	std::string GetTypeName() override;

	~Multicooker() override = default;

};