#pragma once
#include "SeleznevLR3Doc.h"

// Диалоговое окно EditDlg

class EditDlg : public CDialog
{
	DECLARE_DYNAMIC(EditDlg)
	CSeleznevLR3Doc* pDoc;

public:
	EditDlg(CSeleznevLR3Doc* pDocIni, CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~EditDlg();
	void SetVisible(bool vision);

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EditDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CListBox products;
	CEdit edit_Name;
	CEdit edit_Price;
	CEdit edit_Guarantee;
	CEdit edit_Sale;
	CEdit edit_DayOff;
	CString Name;
	int Price;
	int Guarantee;
	int Sale;
	CString DayOff;
	CButton Control;

	afx_msg BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheck1();
};
