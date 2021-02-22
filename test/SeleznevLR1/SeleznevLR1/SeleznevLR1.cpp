#include <iostream>
#include "Seleznev_StockClass.h"
#include "SeleznevLR1.h"
#include "Windows.h"
using namespace std;

int main()
{
	Seleznev_StockClass Stock;
	while (1) {
		setlocale(LC_ALL, "rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		Menu();
		switch (Check(0, 5)) {
		case 0: {exit(0); break;};
		case 1: {Stock.AddProduct();  break; };
		case 2: {Stock.DisplayProducts(); break; };
		case 3: {Stock.ReadFile(); break; };
		case 4: {Stock.WriteFile(); break; };
		case 5: {Stock.Clear(); break; };
		}
	}
}
