#pragma once
#include "pch.h"
#include "Seleznev_SaleClass.h"

class Seleznev_ProductClass;
class EditDlg;

class Seleznev_StockClass
{
private:
	vector<shared_ptr<Seleznev_ProductClass>> Products;
public:
	void AddProduct(EditDlg* dlg, bool SaleProduct, int index = 1);
	int DeleteProduct(int index);
	void ReadFile(CArchive& buf);
	void WriteFile(CArchive& buf);
	void Clear();
	void DrawOnListBox(EditDlg* dlg, int active = -1);
	CSize Drawing(CDC* pDC);
};

