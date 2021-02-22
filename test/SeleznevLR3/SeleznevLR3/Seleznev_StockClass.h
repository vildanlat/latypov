#pragma once
#include "pch.h"
#include "Seleznev_ProductClass.h"
#include "Seleznev_SaleClass.h"

class Seleznev_ProductClass;

class Seleznev_StockClass
{
private:
	vector<shared_ptr<Seleznev_ProductClass>> Products;
public:
	Seleznev_StockClass() {};
	~Seleznev_StockClass() {};
	void AddProduct();
	void DisplayProducts();
	void ReadFile(CArchive& buf);
	void WriteFile(CArchive& buf);
	void Clear();
	CSize Drawing(CDC* pDC);
};

