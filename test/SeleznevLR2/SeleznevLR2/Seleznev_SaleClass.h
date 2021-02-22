#pragma once
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
	void ReadConsole() override;
	void WriteConsole(ostream& buf) override;
	void Serialize(CArchive& buf) override;
};
