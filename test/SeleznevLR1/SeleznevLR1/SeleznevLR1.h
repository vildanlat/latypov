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
		cout << "������� ���������� �����" << endl;
	}
	return buf;
}

inline void Menu()
{
	cout << "1. �������� ����� � ���� ������" << endl
		<< "2. �������� ������� �� ������" << endl
		<< "3. ������� ������ �������  �� �����" << endl
		<< "4. �������� ������ ������� � ����" << endl
		<< "5. �������� ���� �������" << endl
		<< "0. ����� �� ���������" << endl;
}
