#include <iostream>
#include "Utensils.h"
#include "Tree.h"

using namespace std;

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
			switch (typeUtensil)
			{
			case 1:
				uten = new Stove();
				break;
			case 2:
				uten = new Pan();
				break;
			case 3:
				uten = new ElectricStove();
				break;
			case 4:
				uten = new GasStove();
				break;
			case 5:
				uten = new Multicooker();
				break;
			default:
				uten = new Multicooker();
				break;
			}
			bool wasInsert;
			wasInsert = true;
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