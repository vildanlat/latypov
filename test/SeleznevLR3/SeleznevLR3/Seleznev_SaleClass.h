#pragma once
#include "pch.h"
#include "Seleznev_ProductClass.h"


class Seleznev_SaleClass : public Seleznev_ProductClass
{
private:
	int Sale=0;
	CString DayOff;
public:
	DECLARE_SERIAL(Seleznev_SaleClass)
	Seleznev_SaleClass() {};
    ~Seleznev_SaleClass() {};
	virtual void ReadConsole();
	virtual void WriteConsole();
	virtual void Serialize(CArchive& buf);
	virtual void GetLength(CDC* pDC, int* len);
	virtual void OutText(CDC* pDC, int* positions_x, int& position_y, int hight);
};
