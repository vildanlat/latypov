#include "pch.h"
#include "EditDlg.h"
#include "Seleznev_ProductClass.h"

IMPLEMENT_SERIAL(Seleznev_ProductClass, CObject, 0);

CString Seleznev_ProductClass::ReadString()
{
	string buf;
	cin >> buf;
	cin.clear();
	cin.ignore(32767, '\n');
	return CString(buf.c_str());
}

void Seleznev_ProductClass::Serialize(CArchive& buf)
{
	CObject::Serialize(buf);
	if (buf.IsStoring()) buf << Name << Price << Guarantee;
	else buf >> Name >> Price >> Guarantee;
}
void Seleznev_ProductClass::GetLength(CDC* pDC, int* len)
{
	len[0] = pDC->GetTextExtent(Name).cx;
	CString Cstr;
	Cstr = to_string(Price).c_str();
	len[1] = pDC->GetTextExtent(Cstr).cx;
	Cstr = to_string(Guarantee).c_str();
	len[2] = pDC->GetTextExtent(Cstr).cx;
	len[3] = 0;
	len[4] = 0;
}

void Seleznev_ProductClass::OutText(CDC* pDC, int* positions_x, int& position_y, int hight)
{
	pDC->TextOut(positions_x[0], position_y, Name);
	CString Cstr;
	Cstr = to_string(Price).c_str();
	pDC->TextOut(positions_x[1], position_y, Cstr);
	Cstr = to_string(Guarantee).c_str();
	pDC->TextOut(positions_x[2], position_y, Cstr);
	position_y += hight;
}

void Seleznev_ProductClass::ReadField(EditDlg* dlg)
{
	dlg->UpdateData(true);
	Name = dlg->Name;
	Price = dlg->Price;
	Guarantee = dlg->Guarantee;
	dlg->UpdateData(false);
	dlg->SetVisible(false);
}

void Seleznev_ProductClass::WriteField(EditDlg* dlg)
{
	dlg->Name = Name;
	dlg->Price = Price;
	dlg->Guarantee = Guarantee;
	dlg->Control.SetCheck(false);
	dlg->UpdateData(false);
	dlg->SetVisible(false);
}