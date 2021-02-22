#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include "afxwin.h"
using namespace std;

class Seleznev_ProductClass : public CObject
{
protected:
	CString Name;
	int Price;
	int Guarantee;
public:
	DECLARE_SERIAL(Seleznev_ProductClass)
	CString ReadString();
	Seleznev_ProductClass();
	virtual ~Seleznev_ProductClass();
	void setName(CString& name);
	void setPrice(int& price);
	void setGuarantee(int& guarantee);
	virtual void setSale(int& sale);
	virtual void setDayOff(CString& dayOff);
	CString getName();
	int getPrice();
	int getGuarantee();
	virtual int getSale();
	virtual CString getDayOff();
	virtual bool isSale ();
	virtual void Serialize(CArchive& buf);
};
