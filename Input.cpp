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
		if (s == "y") return true;
		if (s == "n") return false;
		cout << "Repeat (only \"y\" or \"n\")" << endl;
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
			cout << "Write only number" << endl;
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