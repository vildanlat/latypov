#pragma once
#include <string>
#include <iostream>
using namespace std;

template < typename type >
type Check(const type& min, const type& max) {
	type buf;
	while (!(cin >> buf) || buf > max || buf < min) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Введите подходящее число" << endl;
	}
	return buf;
}

inline void Menu()
{
	cout << "1. Добавить товар в базу склада" << endl
		<< "2. Просмотр товаров на складе" << endl
		<< "3. Считать список товаров  из файла" << endl
		<< "4. Записать список товаров в файл" << endl
		<< "5. Очистить базу товаров" << endl
		<< "0. Выход из программы" << endl;
}
