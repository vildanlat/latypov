#include "pch.h"
#include "Seleznev_StockClass.h"
#include "Services.h"

void Seleznev_StockClass::Clear()
{
	Products.clear();
}

void Seleznev_StockClass::AddProduct()
{
	cout << "0. Добавить обычный товар" << endl
		<< "1. Добавить товар со скидкой" << endl;
	bool flag = Check(0, 1);
	if (flag==0) {
		shared_ptr<Seleznev_ProductClass> product = make_shared<Seleznev_ProductClass>();
		product->ReadConsole();
		Products.push_back(product);
	}
	else {
		shared_ptr<Seleznev_SaleClass> sale = make_shared<Seleznev_SaleClass>();
		sale->ReadConsole();
		Products.push_back(sale);
	}
}

void Seleznev_StockClass::DisplayProducts()
{
	for (shared_ptr<Seleznev_ProductClass> product : Products) 	product->WriteConsole();
}

void Seleznev_StockClass::ReadFile(CArchive& ar)
{
	int size;
	ar >> size;
	for (int i = 0; i < size; i++)
	{
		Seleznev_ProductClass* product;
		ar >> product;
		Products.push_back(shared_ptr<Seleznev_ProductClass>(product));
	}
}

void Seleznev_StockClass::WriteFile(CArchive& ar)
{
	ar << Products.size();
	for (auto product : Products)
	{
		ar << product.get();
	}
}
CSize Seleznev_StockClass::Drawing(CDC* pDC)
{
	//отступы
	int left = 20;
	int top = 20;
	int indent = 30;

	//заголовок 
	CString Title[5];
	Title[0] = "Имя";
	Title[1] = "Стоимость";
	Title[2] = "Гарантия";
	Title[3] = "Скидка";
	Title[4] = "Окончание скидки";

	//длины частей заголовка
	int len[5];
	for (int i = 0; i < 5; i++)
	{
		len[i] = pDC->GetTextExtent(Title[i]).cx;
	}

	//длины для выводимого текста
	for (auto product : Products)
	{
		int new_len[5];
		product->GetLength(pDC, new_len);

		for (int i = 0; i < 5; i++)
			if (new_len[i] > len[i]) len[i] = new_len[i];
	}

	//координаты x 
	int from_left[5];
	from_left[0] = left;
	for (int i = 1; i < 5; i++)
	{
		from_left[i] = from_left[i - 1] + len[i - 1] + indent;
	}


	//вывод
	for (int i = 0; i < 5; i++)
	{
		pDC->TextOut(from_left[i], top, Title[i]);
	}
	top += indent;

	for_each(Products.begin(), Products.end(), bind(&Seleznev_ProductClass::OutText, placeholders::_1, pDC, from_left, ref(top), indent));


	// размер всей области
	SIZE result;
	result.cx = from_left[4] + len[4] + 20;
	result.cy = top + 20;
	return result;
}