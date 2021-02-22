#include <vector>
#include <memory>
#include "Seleznev_ProductClass.h"

class Seleznev_ProductClass;

class Seleznev_StockClass
{
private:
	vector<shared_ptr<Seleznev_ProductClass>> Products;
public:
	void AddProduct();
	void DisplayProducts();
	void ReadFile();
	void WriteFile();
	void Clear();
};

