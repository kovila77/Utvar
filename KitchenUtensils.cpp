#include "KitchenUtensils.h"
#include <iostream>
#include <string>
#include "Input.h"

KitchenUtensils::KitchenUtensils()
{
	std::cout << "�������� ������..." << std::endl;
	std::cout << "������� ����������� �����: "<< std::endl;
	inventoryNumber = inputInt();
}

void KitchenUtensils::print()
{
	std::cout << "����������� �����: " << inventoryNumber << std::endl;
}