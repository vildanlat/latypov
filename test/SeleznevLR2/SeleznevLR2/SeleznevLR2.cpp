#include <iostream>
#include "latypov_StockClass.h"
#include "latypov_laba2.h"
using namespace std;

void Menu()
{
	cout << "1. Добавить товар в базу склада" << endl
		<< "2. Просмотр товаров на складе" << endl
		<< "3. Считать список товаров  из файла" << endl
		<< "4. Записать список товаров в файл" << endl
		<< "5. Очистить базу товаров" << endl
		<< "0. Выход из программы" << endl;
}

int main()
{
	latypov_StockClass Stock = latypov_StockClass();
	while (1) {
		setlocale(LC_ALL, "rus");
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		Menu();
		switch (Check(0, 5)) {
		case 0: {exit(0); break; };
		case 1: {Stock.AddProduct();  break; };
		case 2: {Stock.DisplayProducts(); break; };
		case 3: {Stock.ReadFile(); break; };
		case 4: {Stock.WriteFile(); break; };
		case 5: {Stock.Clear(); break; };
		}
	}
}
