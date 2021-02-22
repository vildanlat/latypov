// EditDlg.cpp: файл реализации
//

#include "pch.h"
#include "EditDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "Seleznev_StockClass.h"
#include "SeleznevLR3.h"


// Диалоговое окно EditDlg

IMPLEMENT_DYNAMIC(EditDlg, CDialog)

EditDlg::EditDlg(CSeleznevLR3Doc* pDocIni, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_EditDlg, pParent)
	, Name("")
	, Price(0)
	, Guarantee(0)
	, Sale(0)
	, DayOff("")
{
	this->pDoc = pDocIni;
}

EditDlg::~EditDlg()
{
}

void EditDlg::DoDataExchange(CDataExchange* pDX)
{
	DDX_Control(pDX, IDC_LIST1, products);
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit_Name);
	DDX_Control(pDX, IDC_EDIT2, edit_Price);
	DDX_Control(pDX, IDC_EDIT3, edit_Guarantee);
	DDX_Control(pDX, IDC_EDIT4, edit_Sale);
	DDX_Control(pDX, IDC_EDIT5, edit_DayOff);
	DDX_Control(pDX, IDC_CHECK1, Control);
	
	DDX_Text(pDX, IDC_EDIT1, Name);
	DDX_Text(pDX, IDC_EDIT2, Price);
	DDX_Text(pDX, IDC_EDIT3, Guarantee);
	DDX_Text(pDX, IDC_EDIT4, Sale);
	DDX_Text(pDX, IDC_EDIT5, DayOff);

}

BEGIN_MESSAGE_MAP(EditDlg, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &EditDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &EditDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &EditDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT4, &EditDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT5, &EditDlg::OnEnChangeEdit1)
	ON_LBN_SELCHANGE(IDC_LIST1, &EditDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &EditDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &EditDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &EditDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &EditDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &EditDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()

void EditDlg::SetVisible(bool vision) {
	int visible = (vision) ? SW_SHOW : SW_HIDE;
	edit_Sale.ShowWindow(visible);
	edit_DayOff.ShowWindow(visible);
}
// Обработчики сообщений EditDlg

BOOL EditDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetVisible(IsDlgButtonChecked(IDC_CHECK1));
	pDoc->Stock.DrawOnListBox(this);
	return TRUE;
}


void EditDlg::OnBnClickedOk()
{
	CDialog::OnOK();
}


void EditDlg::OnBnClickedCheck1()
{
	SetVisible(IsDlgButtonChecked(IDC_CHECK1));
	OnEnChangeEdit1();
}

void EditDlg::OnLbnSelchangeList1()
{
	pDoc->Stock.DrawOnListBox(this, products.GetCurSel());
}

void EditDlg::OnBnClickedButton1()
{
	pDoc->Stock.AddProduct(this, false, -1);
	pDoc->Stock.DrawOnListBox(this);
	this->products.SetCurSel(products.GetCount()-1);
	OnLbnSelchangeList1();

}


void EditDlg::OnBnClickedButton2()
{
	pDoc->Stock.AddProduct(this, true, -1);
	pDoc->Stock.DrawOnListBox(this);
	this->products.SetCurSel(products.GetCount()-1);
	OnLbnSelchangeList1();
}

void EditDlg::OnBnClickedButton3()
{
	int curSel = products.GetCurSel();
	if (curSel < 0) return;
	curSel = pDoc->Stock.DeleteProduct(curSel);
	pDoc->Stock.DrawOnListBox(this);
	if (curSel == products.GetCount()) curSel--;
	this->products.SetCurSel(curSel);
}

void EditDlg::OnEnChangeEdit1()
{
	int curSel = products.GetCurSel();
	if (curSel > -1) {
		pDoc->Stock.AddProduct(this, IsDlgButtonChecked(IDC_CHECK1), curSel);
		pDoc->Stock.DrawOnListBox(this, curSel);
	}
}
