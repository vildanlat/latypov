#include "Seleznev_StockClass.h"

string GetPath() {
	string pathtofile;
	cout << "Введите путь до файла:" << endl;
	cin >> pathtofile;
	return pathtofile;
}

void Seleznev_StockClass::AddProduct()
{
	auto product = make_shared<Seleznev_ProductClass>();
	product->ReadConsole(cin);
	Products.push_back(product);
}

void Seleznev_StockClass::DisplayProducts()
{
	for (shared_ptr<Seleznev_ProductClass> product : Products)
		(*product).WriteConsole(cout);
}

void Seleznev_StockClass::ReadFile()
{
	ifstream file;
	string path = GetPath();
	file.open(path);
	if (!file) {
		cout << "Ошибка при открытии файла. Пожалуйста, попробуйте еще раз." << endl;
		return;
	}
	while (!file.eof()) {
		auto product = make_shared<Seleznev_ProductClass>();
		product->ReadFile(file);
		Products.push_back(product);
	}
	file.close();
}

void Seleznev_StockClass::WriteFile()
{
	ofstream file;
	string path = GetPath();
	file.open(path);
	for (shared_ptr<Seleznev_ProductClass> product:Products) {
		(*product).WriteFile(file);
	}
	file.close();
}

void Seleznev_StockClass::Clear()
{
	Products.clear();
}
