#include <iostream>
#include "Utensils.h"
#include "Tree.h"

using namespace std;

int main()
{
	//cout << "hello world (" << endl;
	setlocale(LC_ALL, "Russian");

	//cout << endl;

	//Stove ms(1, 1);
	//ms.print();

	//cout << endl;

	//Pan p(3, 2);
	//p.print();

	//cout << endl;

	//GasStove gs(1, 2, 3);
	//gs.print();

	//cout << endl;	
	//
	//ElectricStove es(1, 2, 4);
	//es.print();

	//cout << endl;

	/*Multicooker mk(true, 1, 2, 3, 4);
	mk.print(); */

	//cout << endl;

	//Multicooker* mk2 = new Multicooker(false, 14, 2500, 255, 16992);
	//mk2->print();

	//cout << endl;

	//KitchenUtensils* ku;
	//ku = mk2;
	//ku->print();

	//cout << endl;

	//PTree r = nullptr;
	//bool res;
	//
	//Insert(r, 4, res);
	//Insert(r, 5, res);
	//Insert(r, 6, res);
	//Insert(r, 1, res);
	//Insert(r, 3, res);

	//PrintTree(r, 1);

	//DeleteTree(r);

	//PTree gg = nullptr;
	//bool tmp;

	//Insert(gg, new Stove(1, 2), tmp);

	//PrintTree(gg, 1);

	//DeleteTree(gg);

	/*cout << "dfd" << endl;
	int f = inputInt();*/

	//Multicooker mk;

	cout << endl;

	int act;
	PTree root = nullptr;
	while (true)
	{
		cout << "Выберете дейсвие :" << endl;
		cout << "1 Ввод" << endl;
		cout << "2 Удаление" << endl;
		cout << "3 Вывод" << endl;
		cout << "4 Выход" << endl;
		while (true)
		{
			act = inputInt();
			if (act >= 0 && act <= 4)
			{
				break;
			}
			std::cout << "Действие должно быть 1, 2, 3 или 4" << std::endl;
		}
		switch (act)
		{
		case 1:
			int typeUtensil;
			KitchenUtensils* uten;
			cout << "Выберете утварь :" << endl;
			cout << "1 Плита" << endl;
			cout << "2 Кастрюля" << endl;
			cout << "3 Плита электрическая" << endl;
			cout << "4 Плита газовая" << endl;
			cout << "5 Мультиварка" << endl;
			while (true)
			{
				typeUtensil = inputInt();
				if (typeUtensil >= 0 && typeUtensil <= 5)
				{
					break;
				}
				std::cout << "Утварь должна быть 1, 2, 3, 4 или 5" << std::endl;
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
			cout << "Введите инвентарный номер утвари для удаления:" << endl;
			int cr = 0, in = inputInt();
			deletFromTree(root, in, cr, false);
			break;
		}
		case 3:
			int typePrint;
			cout << "Выберете тип обхода :" << endl;
			cout << "1 Прямой" << endl;
			cout << "2 Обратный" << endl;
			cout << "3 Симметричный" << endl;
			while (true)
			{
				typePrint = inputInt();
				if (typePrint >= 0 && typePrint <= 3)
				{
					break;
				}
				std::cout << "Тип должен быть 1, 2 или 3" << std::endl;
			}
			cout << endl;
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
			cout << endl;
			break;
		case 4: {
			std::cout << "Подтверждаете выход?" << std::endl;
			string s;
			cin >> s;
			if (s == "y" || s == "Y" || s == "д" || s == "Д")
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