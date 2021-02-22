#pragma once
#include "pch.h"
#include <vector>
#include <memory>
#include "Seleznev_ProductClass.h"
#include "Seleznev_SaleClass.h"

class Seleznev_ProductClass;

class Seleznev_StockClass
{
private:
	vector<shared_ptr<Seleznev_ProductClass>> Products;
public:
	int getQuantity();
	void setName(int& index, CString& Name);
	void setPrice(int& index, int& Price);
	void setGuarantee(int& index, int& Guarantee);
	void setSale(int& index, int& Sale);
	void setDayOff(int& index, CString& DayOff);
	CString getName(int& index);
	int getPrice(int& index);
	int getGuarantee(int& index);
	int getSale (int& index);
	CString getDayOff(int& index);

	void changeClass(int& index, int& isSale);
	bool isSale(int& index);
	void DeleteProduct(int& index);
	void AddProduct(int& isSale);
	void ReadFile(CString& filename);
	void WriteFile(CString& filename);
	void Clear();
};
