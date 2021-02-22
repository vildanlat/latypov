// MFC_DLL.h: основной файл заголовка для библиотеки DLL MFC_DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы
#include "pch.h"

// CMFCDLLApp
// Реализацию этого класса см. в файле MFC_DLL.cpp
//

class CMFCDLLApp : public CWinApp
{
public:
	CMFCDLLApp();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
