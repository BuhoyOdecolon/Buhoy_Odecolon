#include "stdafx.h"
#include <iostream>
#include <locale.h>
using namespace std;



int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "\t\t\tПеревод числа из метров в километры\n\n\n";
	float a;
	cout << "Введите количество метров: ";
	cin >> a;
	cout << "\n";
	if (a == 1)
	{
		cout << a << " метр будет " << a / 1000 << " километра " << endl;
	}
	if (a>1 && a <= 4)
	{
		cout << a << " метрa будет " << a / 1000 << " километра " << endl;
	}
	if (a >= 5 && a<1000)
	{
		cout << a << " метров будет " << a / 1000 << " километра " << endl;
	}
	if (a == 1000)
	{
		cout << a << " метров будет " << a / 1000 << " километр " << endl;
	}
	if (a>1000 && a <= 4900)
	{
		cout << a << " метров будет " << a / 1000 << " километрa " << endl;
	}
	if (a >= 5000)
	{
		cout << a << " метров будет " << a / 1000 << " километров " << endl;
	}
	cout << endl;
	return 0;
}

