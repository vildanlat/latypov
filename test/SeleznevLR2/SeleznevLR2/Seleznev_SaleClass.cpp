#include "Seleznev_SaleClass.h"
#include "SeleznevLR2.h"

IMPLEMENT_SERIAL(Seleznev_SaleClass, Seleznev_ProductClass, 1);
Seleznev_SaleClass::Seleznev_SaleClass() {}
Seleznev_SaleClass::~Seleznev_SaleClass() {}

void Seleznev_SaleClass::ReadConsole()
{
	Seleznev_ProductClass::ReadConsole();

	cout << "������� ������ ������: ";
	Sale = Check(0,9999999);
	cout << "������� ���� ��������� ������: ";
	DayOff = Seleznev_ProductClass::ReadString();
}

void Seleznev_SaleClass::WriteConsole(ostream& cout)
{
	Seleznev_ProductClass::WriteConsole(cout);
	cout << "������ ������: " << Sale << " ���� ��������� ������: " << (LPCTSTR)DayOff << endl;
}

void Seleznev_SaleClass::Serialize(CArchive& buf)
{
	Seleznev_ProductClass::Serialize(buf);
	if (buf.IsStoring()) buf << Sale << DayOff;
	else buf >> Sale >> DayOff;
}
