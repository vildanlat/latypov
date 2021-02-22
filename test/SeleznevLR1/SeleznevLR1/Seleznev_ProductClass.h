#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Seleznev_ProductClass
{
private:
	string Name;
	int Price;
	int Guarantee;
	bool Avaliability;
public:
	void ReadConsole(istream& buf);
	void WriteConsole(ostream& buf);
	void ReadFile(ifstream& buf);
	void WriteFile(ofstream& buf);
};
