#include "pch.h"
#include "Seleznev_StockClass.h"
#include "EditDlg.h"

void Seleznev_StockClass::Clear()
{
	Products.clear();
}

void Seleznev_StockClass::AddProduct(EditDlg* dlg, bool SaleProduct, int index)
{
	shared_ptr<Seleznev_ProductClass> product;
	if (SaleProduct) product = make_shared<Seleznev_SaleClass>();
	else product = make_shared<Seleznev_ProductClass>();
	if (index < 0)Products.push_back(product);
	else {product->ReadField(dlg);
	Products[index] = product; }
}

int Seleznev_StockClass::DeleteProduct(int index)
{
	Products.erase(Products.begin() + index);
	if (index >= Products.size()) index--;
	return index;
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
	int left = 20;
	int top = 20;
	int indent = 30;
	CString Title[5];
	Title[0] = "Имя";
	Title[1] = "Стоимость";
	Title[2] = "Гарантия";
	Title[3] = "Скидка";
	Title[4] = "Окончание скидки";
	int len[5];
	for (int i = 0; i < 5; i++)
	{
		len[i] = pDC->GetTextExtent(Title[i]).cx;
	}
	for (auto product : Products)
	{
		int new_len[5];
		product->GetLength(pDC, new_len);
		for (int i = 0; i < 5; i++)
			if (new_len[i] > len[i]) len[i] = new_len[i];
	}
	int from_left[5];
	from_left[0] = left;
	for (int i = 1; i < 5; i++)
	{
		from_left[i] = from_left[i - 1] + len[i - 1] + indent;
	}
	for (int i = 0; i < 5; i++)
	{
		pDC->TextOut(from_left[i], top, Title[i]);
	}
	top += indent;
	for_each(Products.begin(), Products.end(), bind(&Seleznev_ProductClass::OutText, placeholders::_1, pDC, from_left, ref(top), indent));
	SIZE result;
	result.cx = from_left[4] + len[4] + 20;
	result.cy = top + 20;
	return result;
}

void Seleznev_StockClass::DrawOnListBox(EditDlg* dlg, int active)
{
	dlg->products.ResetContent();
	if (Products.empty()) return;
	if (active > -1) Products[active]->WriteField(dlg);
	for_each(Products.begin(), Products.end(), [&](shared_ptr<Seleznev_ProductClass> product)
		{
			dlg->products.AddString(product->Name);
		});
	dlg->products.SetCurSel(active);
}