#include "pch.h"
#include "Seleznev_SaleClass.h"
#include "SeleznevLR2.h"

IMPLEMENT_SERIAL(Seleznev_SaleClass, Seleznev_ProductClass, 1);
Seleznev_SaleClass::Seleznev_SaleClass() {}
Seleznev_SaleClass::~Seleznev_SaleClass() {}

CString Seleznev_SaleClass::getDayOff()
{
	return DayOff;
}

int Seleznev_SaleClass::getSale()
{
	return Sale;
}

void Seleznev_SaleClass::setDayOff(CString& DayOff)
{
	this->DayOff = DayOff;
}

void Seleznev_SaleClass::setSale(int& Sale)
{
	this->Sale = Sale;
}


bool Seleznev_SaleClass::isSale()
{
	return true;
}
void Seleznev_SaleClass::Serialize(CArchive& buf)
{
	Seleznev_ProductClass::Serialize(buf);
	if (buf.IsStoring()) buf << Sale << DayOff;
	else buf >> Sale >> DayOff;
}
