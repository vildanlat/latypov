
// SeleznevLR3.h: основной файл заголовка для приложения SeleznevLR3
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы
#include "SeleznevLR3Doc.h"
#include "EditDlg.h"


// CSeleznevLR3App:
// Сведения о реализации этого класса: SeleznevLR3.cpp
//

class CSeleznevLR3App : public CWinApp
{
public:
	CSeleznevLR3App() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSeleznevLR3App theApp;
