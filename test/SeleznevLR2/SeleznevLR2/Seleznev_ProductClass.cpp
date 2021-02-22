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
void Seleznev_ProductClass::ReadConsole()
{
	Seleznev_ProductClass product;
	cout << "������� �������� ������:" << endl;
	product.Name = ReadString();
	cout << "������� ��������� ������:" << endl;
	product.Price=Check(0, 999999);
	cout << "������� ���� ��������:" << endl;
	product.Guarantee=Check(0, 999999);
	cout << "���� �� ����� � �������? (1-��, 0-���)" << endl;
	product.Avaliability=Check(0, 1);
}

void Seleznev_ProductClass::WriteConsole(ostream& buf)
{
	cout << "�������� ������: <" << (LPCTSTR)Name << "> ��������� ������: " << Price << "���. ���� ��������: " << Guarantee << "��� �������: ";
	if (Avaliability == 1) cout << "��" << endl;
	else cout << "���" << endl;
}

void Seleznev_ProductClass::Serialize(CArchive& buf)
{
	CObject::Serialize(buf);
	if (buf.IsStoring()) buf << Name << Price << Guarantee << Avaliability;
	else buf >> Name >> Price >> Guarantee >> Avaliability;
}
