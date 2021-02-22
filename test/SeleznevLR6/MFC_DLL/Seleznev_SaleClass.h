#pragma once
#include "pch.h"
#include "Seleznev_ProductClass.h"

class Seleznev_SaleClass : public Seleznev_ProductClass
{
private:
	int Sale;
	CString DayOff;
public:
	DECLARE_SERIAL(Seleznev_SaleClass)
	Seleznev_SaleClass();
	virtual ~Seleznev_SaleClass();
	CString getDayOff() override;
	int getSale() override;
	void setDayOff(CString& DayOff) override;
	void setSale(int& Sale) override;
	bool isSale() override;
	void Serialize(CArchive& buf) override;
};
