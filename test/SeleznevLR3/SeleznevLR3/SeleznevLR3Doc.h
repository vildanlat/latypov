
// SeleznevLR3Doc.h: интерфейс класса CSeleznevLR3Doc 
//


#pragma once
#include "Seleznev_StockClass.h"

class CSeleznevLR3Doc : public CDocument
{
protected: // создать только из сериализации
	CSeleznevLR3Doc() noexcept;
	DECLARE_DYNCREATE(CSeleznevLR3Doc)

// Атрибуты
public:
	Seleznev_StockClass Stock;
// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CSeleznevLR3Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
