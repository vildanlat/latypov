#pragma once
#include "pch.h"

class EditDlg;

class Seleznev_ProductClass : public CObject
{
public:
	CString Name= CString("Новый");
	int Price = 0;
	int Guarantee = 0;
	DECLARE_SERIAL(Seleznev_ProductClass)
	CString ReadString();
	Seleznev_ProductClass() {};
	virtual ~Seleznev_ProductClass() {}
	virtual void Serialize(CArchive& buf);
	virtual void GetLength(CDC* pDC, int* len);
	virtual void OutText(CDC* pDC, int* positions_x, int& posotion_y, int hight);
	virtual void ReadField(EditDlg* dlg);
	virtual void WriteField(EditDlg* dlg);
};
