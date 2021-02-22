#include "pch.h"
#include "Seleznev_ProductClass.h"
#include "Services.h"


IMPLEMENT_SERIAL(Seleznev_ProductClass, CObject, 0);

CString Seleznev_ProductClass::ReadString()
{
	string buf;
	cin >> buf;
	cin.clear();
	cin.ignore(32767, '\n');
	return CString(buf.c_str());
}


void Seleznev_ProductClass::ReadConsole()
{
	cout << "Введите название товара:" << endl;
	Name = ReadString();
	cout << "Введите стоимость товара:" << endl;
	Price = Check(0, 999999);
	cout << "Введите срок гарантии:" << endl;
	Guarantee = Check(0, 999999);
}

void Seleznev_ProductClass::WriteConsole()
{
	cout << "Название товара: <" << (LPCTSTR)Name << "> Стоимость товара: " << Price << "руб. Срок гарантии: " << Guarantee << "лет"<<endl;
}

void Seleznev_ProductClass::Serialize(CArchive& buf)
{
	if (buf.IsStoring()) buf << Name << Price << Guarantee;
	else buf >> Name >> Price >> Guarantee;
}
void Seleznev_ProductClass::GetLength(CDC* pDC, int* len)
{
	len[0] = pDC->GetTextExtent(Name).cx;
	CString Cstr;
	Cstr = to_string(Price).c_str();
	len[1] = pDC->GetTextExtent(Cstr).cx;
	Cstr = to_string(Guarantee).c_str();
	len[2] = pDC->GetTextExtent(Cstr).cx;
	len[3] = 0;
	len[4] = 0;
}

void Seleznev_ProductClass::OutText(CDC* pDC, int* positions_x, int& position_y, int hight)
{
	pDC->TextOut(positions_x[0], position_y, Name);
	CString Cstr;
	Cstr = to_string(Price).c_str();
	pDC->TextOut(positions_x[1], position_y, Cstr);
	Cstr = to_string(Guarantee).c_str();
	pDC->TextOut(positions_x[2], position_y, Cstr);
	position_y += hight;
}