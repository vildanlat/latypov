#pragma once
#include <vector>
#include <memory>
#include "Seleznev_ProductClass.h"
#include "Seleznev_SaleClass.h"

class Seleznev_ProductClass;

class Seleznev_StockClass
{
private:
	vector<shared_ptr<Seleznev_ProductClass>> Products;
	CString GetPath();
public:
	void AddProduct();
	void DisplayProducts();
	void ReadFile();
	void WriteFile();
	void Clear();
};

