#include "Input.h"
#include <iostream>
#include <string>

using namespace std;

bool inputBool()
{
	string s;
	while (true)
	{
		getline(cin, s);
		if (s == "y" || s == "Y" || s == "д" || s == "Д") return true;
		if (s == "n" || s == "N" || s == "н" || s == "Н") return false;
		cout << "Повторите (только \"y\" или \"д\" для yes, \"n\" или \"н\" для no)" << endl;
	}
}

int inputInt()
{
	bool ok = false;
	int newI = 2;
	while (!ok)
	{
		intputInt(ok, newI);
		if (ok)
		{
			break;
		}
		else
		{
			cout << "Вводите только цифры" << endl;
		}
	}
	return newI;
}

void intputInt(bool& InputIsTrue, int& i)
{
	string s;
	getline(cin, s);

	InputIsTrue = true;
	if (s == "0")
	{
		i = 0;
	}
	else
	{
		try
		{
			i = stoi(s);
			if (i == 0) InputIsTrue = false;
		}
		catch (exception)
		{
			InputIsTrue = false;
		}
	}
}