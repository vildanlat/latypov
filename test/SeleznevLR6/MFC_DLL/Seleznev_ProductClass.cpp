#include "pch.h"
#include "Seleznev_ProductClass.h"
#include "SeleznevLR2.h"

IMPLEMENT_SERIAL(Seleznev_ProductClass, CObject, 1);
Seleznev_ProductClass::Seleznev_ProductClass() {}
Seleznev_ProductClass::~Seleznev_ProductClass() {}

CString Seleznev_ProductClass::ReadString()
{
	string buf;
	cin >> buf;
	return CString(buf.c_str());
}
void Seleznev_ProductClass::setName(CString& name)
{
	Name = name;
}

void Seleznev_ProductClass::setPrice(int& price)
{
	Price = price;
}

void Seleznev_ProductClass::setGuarantee(int& guarantee)
{
	Guarantee = guarantee;
}

void Seleznev_ProductClass::setSale(int& sale)
{
}

void Seleznev_ProductClass::setDayOff(CString& dayOff)
{
}

CString Seleznev_ProductClass::getName()
{
	return Name;
}

int Seleznev_ProductClass::getPrice()
{
	return Price;
}

int Seleznev_ProductClass::getGuarantee()
{
	return Guarantee;
}

int Seleznev_ProductClass::getSale()
{
	return -1;
}

CString Seleznev_ProductClass::getDayOff()
{
	return CString();
}

bool Seleznev_ProductClass::isSale()
{
	return false;
}

void Seleznev_ProductClass::Serialize(CArchive& buf)
{
	CObject::Serialize(buf);
	if (buf.IsStoring()) buf << Name << Price << Guarantee;
	else buf >> Name >> Price >> Guarantee;
}
