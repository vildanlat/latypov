#pragma once
#include "pch.h"
#include "Seleznev_ProductClass.h"

class EditDlg;

class Seleznev_SaleClass : public Seleznev_ProductClass
{
public:
	int Sale = 0;
	CString DayOff;
	DECLARE_SERIAL(Seleznev_SaleClass)
	Seleznev_SaleClass() {};
    virtual ~Seleznev_SaleClass() {};
	virtual void Serialize(CArchive& buf) override;
	virtual void GetLength(CDC* pDC, int* len) override;
	virtual void OutText(CDC* pDC, int* positions_x, int& position_y, int hight) override;
	virtual void ReadField(EditDlg* dlg) override;
	virtual void WriteField(EditDlg* dlg) override;
};
