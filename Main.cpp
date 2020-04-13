#include <iostream>
#include "KitchenUtensils.h"
#include "Stove.h"
#include "Pan.h"
#include "ElectricStove.h"
#include "GasStove.h"
#include "Multicooker.h"
#include "Input.h"
#include "Tree.h"

using namespace std;

KitchenUtensils* MakeUten(int type, PTree root);
int GetINventoryNumber(PTree root);

string GetColor();
int GetVolume();

int GetPower();

int GetGasConsumption();
bool GetHaveFastFunction();

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << endl;

	int act;
	PTree root = nullptr;
	while (true)
	{
		cout << "�������� ������� :" << endl;
		cout << "1 ����" << endl;
		cout << "2 ��������" << endl;
		cout << "3 �����" << endl;
		cout << "4 �����" << endl;
		while (true)
		{
			act = inputInt();
			if (act >= 0 && act <= 4)
			{
				break;
			}
			std::cout << "�������� ������ ���� 1, 2, 3 ��� 4" << std::endl;
		}
		switch (act)
		{
		case 1:
			int typeUtensil;
			KitchenUtensils* uten;
			cout << "�������� ������ :" << endl;
			cout << "1 �����" << endl;
			cout << "2 ��������" << endl;
			cout << "3 ����� �������������" << endl;
			cout << "4 ����� �������" << endl;
			cout << "5 �����������" << endl;
			while (true)
			{
				typeUtensil = inputInt();
				if (typeUtensil >= 0 && typeUtensil <= 5)
				{
					break;
				}
				std::cout << "������ ������ ���� 1, 2, 3, 4 ��� 5" << std::endl;
			}
			uten = MakeUten(typeUtensil, root);
			bool  wasInsert; wasInsert = true;
			Insert(root, uten, wasInsert);
			if (!wasInsert)
			{
				delete uten;
			}
			break;
		case 2: {
			cout << "������� ����������� ����� ������ ��� ��������:" << endl;
			int cr = 0, in = inputInt();
			deletFromTree(root, in, cr, false);
			break;
		}
		case 3:
			int typePrint;
			cout << "�������� ��� ������ :" << endl;
			cout << "1 ������" << endl;
			cout << "2 ��������" << endl;
			cout << "3 ������������" << endl;
			while (true)
			{
				typePrint = inputInt();
				if (typePrint >= 0 && typePrint <= 3)
				{
					break;
				}
				std::cout << "��� ������ ���� 1, 2 ��� 3" << std::endl;
			}
			cout << "-------------------------------------------------------------------" << endl;
			switch (typePrint)
			{
			case 1:
				PrintTreeDirect(root, 1);
				break;
			case 2:
				PrintTreeBack(root, 1);
				break;
			case 3:
				PrintTreeSimm(root, 1);
				break;
			}
			cout << "-------------------------------------------------------------------" << endl;
			break;
		case 4: {
			std::cout << "������������� �����?" << std::endl;
			string s;
			cin >> s;
			if (s == "y" || s == "Y" || s == "�" || s == "�")
			{
				DeleteTree(root);
				return 0;
			}
			break;
		}
		default:
			break;
		}
	}
	DeleteTree(root);
	return 0;
}




KitchenUtensils* MakeUten(int type, PTree root)
{
	std::cout << "�������� ������..." << std::endl;
	KitchenUtensils* uten;
	string color;
	int in, volume, power, gc;
	bool hff;
	in = GetINventoryNumber(root);
	switch (type)
	{
	case 1:
		color = GetColor();
		uten = new Stove(in, color);
		break;
	case 2:
		volume = GetVolume();
		uten = new Pan(in, volume);
		break;
	case 3:
		color = GetColor();
		power = GetPower();
		uten = new ElectricStove(in, color, power);
		break;
	case 4:
		color = GetColor();
		gc = GetGasConsumption();
		uten = new GasStove(in, color, gc);
		break;
	/*case 5:
		color = GetColor();
		uten = new Multicooker(in, color, GetPower(), GetVolume(), GetHaveFastFunction());
		break;*/
	default:
		color = GetColor();
		power = GetPower();
		volume = GetVolume();
		uten = new Multicooker(in, color, power, volume, GetHaveFastFunction());
		break;
	}

	return uten;
}

int GetINventoryNumber(PTree root)
{
	std::cout << "������� ����������� �����: " << std::endl;
	int inventoryNumber;
	KitchenUtensils* ku = nullptr;
	while (true)
	{
		inventoryNumber = inputInt();
		ku = Find(root, inventoryNumber);
		if (ku == nullptr)
		{
			return inventoryNumber;
		}
		else
		{
			std::cout << "����� ����������� ����� ��� ���� � ������! �������:" << std::endl;
			std::cout << ku->GetTypeName() << std::endl;
			ku->print();
			std::cout << "������� ������ ����������� �����" << std::endl;
		}
	}
}

string GetColor()
{
	string color;
	std::cout << "������� ����: " << std::endl;
	//std::cin >> color;
	getline(cin, color);
	return color;
}

int GetVolume()
{
	std::cout << "������� �����: " << std::endl;
	return inputInt();
}

int GetPower()
{
	std::cout << "������� ��������: " << std::endl;
	return inputInt();
}

int GetGasConsumption()
{
	std::cout << "������� ������� ���� ����������: " << std::endl;
	return inputInt();
}

bool GetHaveFastFunction()
{
	std::cout << "���� �� ������� ����������? (y, � / n, �): " << std::endl;
	return inputBool();
}