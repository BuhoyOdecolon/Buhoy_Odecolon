#include "stdafx.h"
#include <iostream>
#include <locale.h>
using namespace std;



int main()
{
	setlocale(LC_ALL, "RUS");
	double Money;
	cout << "Введите сумму гривен: ";
		cin >> Money;
	double Dollar = 26.32;
	double Total = Money * Dollar;
		cout << "Сумма в долларах: " << Total << endl;
    return 0;
}

