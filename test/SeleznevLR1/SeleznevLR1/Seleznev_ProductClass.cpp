#include "Seleznev_ProductClass.h"
#include "SeleznevLR1.h"

void Seleznev_ProductClass::ReadConsole(istream& buf)
{
	cout << "Введите название товара:" << endl;
	buf >> Name;
	cout << "Введите стоимость товара:" << endl;
	Price=Check(0, 999999);
	cout << "Введите срок гарантии:" << endl;
	Guarantee=Check(0, 999999);
	cout << "Есть ли товар в наличии? (1-да, 0-нет)" << endl;
	Avaliability=Check(0, 1);
	
}

void Seleznev_ProductClass::WriteConsole(ostream& buf)
{
	buf << "Название товара: <" << Name << "> Стоимость товара: " << Price << "руб. Срок гарантии: " << Guarantee << "лет Наличие: ";
	if (Avaliability == 1) cout << "да" << endl;
	else cout << "нет" << endl;
}

void Seleznev_ProductClass::ReadFile(ifstream& buf)
{
	buf >> Name >> Price >> Guarantee >> Avaliability;
}

void Seleznev_ProductClass::WriteFile(ofstream& buf)
{
	buf << Name << endl << Price << endl << Guarantee << endl << Avaliability << endl;
}
