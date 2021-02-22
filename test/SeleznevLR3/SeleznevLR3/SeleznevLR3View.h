
// SeleznevLR3View.h: интерфейс класса CSeleznevLR3View
//

#pragma once


class CSeleznevLR3View : public CScrollView
{
protected: // создать только из сериализации
	CSeleznevLR3View() noexcept;
	DECLARE_DYNCREATE(CSeleznevLR3View)

// Атрибуты
public:
	CSeleznevLR3Doc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CSeleznevLR3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // версия отладки в SeleznevLR3View.cpp
inline CSeleznevLR3Doc* CSeleznevLR3View::GetDocument() const
   { return reinterpret_cast<CSeleznevLR3Doc*>(m_pDocument); }
#endif

