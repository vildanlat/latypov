#include "pch.h"
#include "Seleznev_StockClass.h"
#include "SeleznevLR2.h"

int Seleznev_StockClass::getQuantity()
{
	return Products.size();
}

void Seleznev_StockClass::setName(int& index, CString& Name)
{
	Products[index]->setName(Name);
}

void Seleznev_StockClass::setPrice(int& index, int& Price)
{
	Products[index]->setPrice(Price);
}

void Seleznev_StockClass::setGuarantee(int& index, int& Guarantee)
{
	Products[index]->setGuarantee(Guarantee);
}

void Seleznev_StockClass::setSale(int& index, int& Sale)
{
	Products[index]->setSale(Sale);
}

void Seleznev_StockClass::setDayOff(int& index, CString& DayOff)
{
	Products[index]->setDayOff(DayOff);
}


CString Seleznev_StockClass::getName(int& index)
{
	return Products[index]->getName();
}

int Seleznev_StockClass::getPrice(int& index)
{
	return Products[index]->getPrice();
}

int Seleznev_StockClass::getGuarantee(int& index)
{
	return Products[index]->getGuarantee();
}

int  Seleznev_StockClass::getSale(int& index)
{
	return Products[index]->getSale();
}

CString Seleznev_StockClass::getDayOff(int& index)
{
	return Products[index]->getDayOff();
}


void Seleznev_StockClass::changeClass(int& index, int& isSale)
{
	CString bufName = Products[index]->getName();
	int bufPrice = Products[index]->getPrice();
	int bufGuarantee = Products[index]->getGuarantee();

	switch (isSale)
	{
	case 0: {
		shared_ptr<Seleznev_ProductClass> product = make_shared<Seleznev_ProductClass>();
		Products[index] = product;
		break;
	}
	case 1: {
		shared_ptr<Seleznev_ProductClass> saleproduct = make_shared<Seleznev_SaleClass>();
		Products[index] = saleproduct;
		break;
	}
	}

	Products[index]->setName(bufName);
	Products[index]->setPrice(bufPrice);
	Products[index]->setGuarantee(bufGuarantee);
}

bool Seleznev_StockClass::isSale(int& index)
{
	return Products[index]->isSale();
}

void Seleznev_StockClass::AddProduct(int& isSale)
{
	if (isSale==0) {
		shared_ptr<Seleznev_ProductClass> product = make_shared<Seleznev_ProductClass>();
		CString newproduct = _T("Новый продукт");
		product->setName(newproduct);
		Products.push_back(product);
	}
	else {
		shared_ptr<Seleznev_SaleClass> sale = make_shared<Seleznev_SaleClass>();
		CString newsaleproduct = _T("Новый продукт со скидкой");
		sale->setName(newsaleproduct);
		Products.push_back(sale);
	}
}

void Seleznev_StockClass::DeleteProduct(int& index)
{
	Products.erase(Products.begin() + index);
}

void Seleznev_StockClass::ReadFile(CString& filename)
{
	CFile file;
	CArchive archive(&file, CArchive::load);
	CFileException fileException;
	file.Open(filename, CFile::modeReadWrite, &fileException);
	if (!file) {
		cout << "Ошибка при открытии файла. Пожалуйста, попробуйте еще раз." << endl;
		return;
	}
	int length;
	archive >> length;
	for (int i = 0; i < length; i++) {
		Seleznev_ProductClass* product;
		archive >> product;
		Products.push_back(shared_ptr<Seleznev_ProductClass>(product));
	}
	archive.Close();
	file.Close();
}

void Seleznev_StockClass::WriteFile(CString& filename)
{
	CFile file;
	CFileException fileException;
	file.Open(filename, CFile::modeReadWrite, &fileException);
	CArchive archive(&file, CArchive::store);
	archive << Products.size();
	for (shared_ptr<Seleznev_ProductClass> product : Products) {
		archive << product.get();
	}
	archive.Close();
	file.Close();
}

void Seleznev_StockClass::Clear()
{
	Products.clear();
}
