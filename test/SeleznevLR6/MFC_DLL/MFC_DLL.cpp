// MFC_DLL.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"
#include "framework.h"
#include "MFC_DLL.h"
#include "Seleznev_StockClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: если эта библиотека DLL динамически связана с библиотеками DLL MFC,
//		все функции, экспортированные из данной DLL-библиотеки, которые выполняют вызовы к
//		MFC, должны содержать макрос AFX_MANAGE_STATE в
//		самое начало функции.
//
//		Например:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// тело нормальной функции
//		}
//
//		Важно, чтобы данный макрос был представлен в каждой
//		функции до вызова MFC.  Это означает, что
//		должен стоять в качестве первого оператора в
//		функции и предшествовать даже любым объявлениям переменных объекта,
//		поскольку их конструкторы могут выполнять вызовы к MFC
//		DLL.
//
//		В Технических указаниях MFC 33 и 58 содержатся более
//		подробные сведения.
//

// CMFCDLLApp

BEGIN_MESSAGE_MAP(CMFCDLLApp, CWinApp)
END_MESSAGE_MAP()


// Создание CMFCDLLApp

CMFCDLLApp::CMFCDLLApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CMFCDLLApp

CMFCDLLApp theApp;


// Инициализация CMFCDLLApp

BOOL CMFCDLLApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

Seleznev_StockClass stock;


extern "C"
{
	_declspec(dllexport) int _stdcall loadData(char* fileName) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		stock.ReadFile(CString(fileName));
		return stock.getQuantity();
	}

	_declspec(dllexport) void _stdcall saveData(char* fileName) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		stock.WriteFile(CString(fileName));
	}

	_declspec(dllexport) void _stdcall getName(int index, char* Name) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		strcpy_s(Name, stock.getName(index).GetLength() + 1, LPCSTR(stock.getName(index)));
	}

	_declspec(dllexport) int _stdcall getPrice(int index) {
		return stock.getPrice(index);
	}

	_declspec(dllexport) int _stdcall getGuarantee(int index) {
		return stock.getGuarantee(index);
	}

	_declspec(dllexport) int _stdcall getSale (int index) {
		return stock.getSale(index);
	}

	_declspec(dllexport) void _stdcall getDayOff(int index, char* dayoff) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		strcpy_s(dayoff, stock.getDayOff(index).GetLength() + 1, LPCSTR(stock.getDayOff(index)));
	}

	_declspec(dllexport) void _stdcall setName(int index, char* Name) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		stock.setName(index, (CString)Name);
	}

	_declspec(dllexport) void _stdcall setPrice(int index, int price) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		stock.setPrice(index, price);
	}

	_declspec(dllexport) void _stdcall setGuarantee(int index, int guarantee) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		stock.setGuarantee(index, guarantee);
	}

	_declspec(dllexport) void _stdcall setSale(int index, int  sale) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		stock.setSale(index, sale);
	}

	_declspec(dllexport) void _stdcall setDayOff(int index, char* DayOff) {
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		stock.setDayOff(index, (CString)(DayOff));
	}

	_declspec(dllexport) void _stdcall changeClass(int index, int isSale) {
		stock.changeClass(index, isSale);
	}

	_declspec(dllexport) void _stdcall AddProduct(int isSale) {
		stock.AddProduct(isSale);
	}

	_declspec(dllexport) void _stdcall DeleteProduct(int index) {
		stock.DeleteProduct(index);
	}

	_declspec(dllexport) int _stdcall isSale (int index) {
		if (stock.isSale(index)) {
			return 1;
		}
		else {
			return 0;
		}
	}
}