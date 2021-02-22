#include "pch.h"
#include "Seleznev_SaleClass.h"
#include "Services.h"
#include "EditDlg.h"
IMPLEMENT_SERIAL(Seleznev_SaleClass, Seleznev_ProductClass, 0);

void Seleznev_SaleClass::ReadField(EditDlg* dlg)
{
	dlg->UpdateData(true);
	Name = dlg->Name;
	Price = dlg->Price;
	Guarantee = dlg->Guarantee;
	Sale = dlg->Sale;
	DayOff = dlg->DayOff;
	dlg->UpdateData(false);
	dlg->SetVisible(true);
}

void Seleznev_SaleClass::WriteField(EditDlg* dlg)
{
	dlg->Name = Name;
	dlg->Price = Price;
	dlg->Guarantee = Guarantee;
	dlg->Sale = Sale;
	dlg->DayOff = DayOff;
	dlg->Control.SetCheck(true);
	dlg->UpdateData(false);
	dlg->SetVisible(true);
}

void Seleznev_SaleClass::Serialize(CArchive& buf)
{	Seleznev_ProductClass::Serialize(buf);
	if (buf.IsStoring()) buf << Sale << DayOff;
	else buf >> Sale >> DayOff;
}

void Seleznev_SaleClass::GetLength(CDC* pDC, int* len)
{
	Seleznev_ProductClass::GetLength(pDC, len);
	CString Cstr;
	Cstr = to_string(Sale).c_str();
	len[3] = pDC->GetTextExtent(Cstr).cx;
	len[4] = pDC->GetTextExtent(DayOff).cx;
}


void Seleznev_SaleClass::OutText(CDC* pDC, int* positions_x, int& position_y, int hight)
{
	CString Cstr;
	Cstr = to_string(Sale).c_str();
	pDC->TextOut(positions_x[3], position_y, Cstr);
	pDC->TextOut(positions_x[4], position_y, DayOff);
	Seleznev_ProductClass::OutText(pDC, positions_x, position_y, hight);

}