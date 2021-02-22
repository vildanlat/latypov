#include "Seleznev_StockClass.h"
#include "SeleznevLR2.h"

CString GetPath() {
	string pathtofile;
	cout << "Введите путь до файла:" << endl;
	cin >> pathtofile;
	return CString(pathtofile.c_str());
}

void Seleznev_StockClass::AddProduct()
{
	wcout << "1. Добавить обычный товар" << endl
		<< "2. Добавить товар со скидкой" << endl;
	bool flag = Check(0, 1);
	if (flag==1) {
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
	for (shared_ptr<Seleznev_ProductClass> product : Products) 	product->WriteConsole(cout);
}

void Seleznev_StockClass::ReadFile()
{
	CFile file;
	CString path = GetPath();
	CArchive archive(&file, CArchive::load);
	CFileException fileException;
	file.Open(path, CFile::modeReadWrite, &fileException);
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

void Seleznev_StockClass::WriteFile()
{
	CFile file;
	CString path = GetPath();
	CFileException fileException;
	file.Open(path, CFile::modeReadWrite, &fileException);
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
