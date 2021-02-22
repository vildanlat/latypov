#include "Seleznev_ProductClass.h"
#include "SeleznevLR1.h"

void Seleznev_ProductClass::ReadConsole(istream& buf)
{
	cout << "������� �������� ������:" << endl;
	buf >> Name;
	cout << "������� ��������� ������:" << endl;
	Price=Check(0, 999999);
	cout << "������� ���� ��������:" << endl;
	Guarantee=Check(0, 999999);
	cout << "���� �� ����� � �������? (1-��, 0-���)" << endl;
	Avaliability=Check(0, 1);
	
}

void Seleznev_ProductClass::WriteConsole(ostream& buf)
{
	buf << "�������� ������: <" << Name << "> ��������� ������: " << Price << "���. ���� ��������: " << Guarantee << "��� �������: ";
	if (Avaliability == 1) cout << "��" << endl;
	else cout << "���" << endl;
}

void Seleznev_ProductClass::ReadFile(ifstream& buf)
{
	buf >> Name >> Price >> Guarantee >> Avaliability;
}

void Seleznev_ProductClass::WriteFile(ofstream& buf)
{
	buf << Name << endl << Price << endl << Guarantee << endl << Avaliability << endl;
}
