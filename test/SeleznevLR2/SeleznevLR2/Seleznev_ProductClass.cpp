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
	cout << "Введите название товара:" << endl;
	product.Name = ReadString();
	cout << "Введите стоимость товара:" << endl;
	product.Price=Check(0, 999999);
	cout << "Введите срок гарантии:" << endl;
	product.Guarantee=Check(0, 999999);
	cout << "Есть ли товар в наличии? (1-да, 0-нет)" << endl;
	product.Avaliability=Check(0, 1);
}

void Seleznev_ProductClass::WriteConsole(ostream& buf)
{
	cout << "Название товара: <" << (LPCTSTR)Name << "> Стоимость товара: " << Price << "руб. Срок гарантии: " << Guarantee << "лет Наличие: ";
	if (Avaliability == 1) cout << "да" << endl;
	else cout << "нет" << endl;
}

void Seleznev_ProductClass::Serialize(CArchive& buf)
{
	CObject::Serialize(buf);
	if (buf.IsStoring()) buf << Name << Price << Guarantee << Avaliability;
	else buf >> Name >> Price >> Guarantee >> Avaliability;
}
