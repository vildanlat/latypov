#pragma once
#include "pch.h"
#include <string>
#include <iostream>
#include "afxwin.h"
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
