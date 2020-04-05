#include <iostream>
#include "Utensils.h"

using namespace std;

void main()
{
	cout << "hello world (" << endl;

	Stove* ms = new Stove(1,2);

	cout << ms->inventoryNumber << endl;

	system("pause");
}