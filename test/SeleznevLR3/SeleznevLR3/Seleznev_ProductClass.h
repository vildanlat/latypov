#pragma once
#include "pch.h"

class Seleznev_ProductClass : public CObject
{
protected:
	CString Name;
	int Price=0;
	int Guarantee=0;
public:
	DECLARE_SERIAL(Seleznev_ProductClass)
	CString ReadString();
	Seleznev_ProductClass() {};
	virtual ~Seleznev_ProductClass() {}
	virtual void ReadConsole();
	virtual void WriteConsole();
	virtual void Serialize(CArchive& buf);
	virtual void GetLength(CDC* pDC, int* len);
	virtual void OutText(CDC* pDC, int* positions_x, int& posotion_y, int hight);
};
