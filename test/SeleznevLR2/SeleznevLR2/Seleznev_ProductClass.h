#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "afxwin.h"
using namespace std;

class Seleznev_ProductClass : public CObject
{
protected:
	CString Name;
	int Price;
	int Guarantee;
	bool Avaliability;
public:
	DECLARE_SERIAL(Seleznev_ProductClass)
	CString ReadString();
	Seleznev_ProductClass();
	virtual ~Seleznev_ProductClass();
	virtual void ReadConsole();
	virtual void WriteConsole(ostream& buf);
	virtual void Serialize(CArchive& buf);
};
