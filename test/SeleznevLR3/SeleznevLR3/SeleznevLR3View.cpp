
// SeleznevLR3View.cpp: реализация класса CSeleznevLR3View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "SeleznevLR3.h"
#endif

#include "SeleznevLR3Doc.h"
#include "SeleznevLR3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSeleznevLR3View

IMPLEMENT_DYNCREATE(CSeleznevLR3View, CScrollView)

BEGIN_MESSAGE_MAP(CSeleznevLR3View, CScrollView)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()
// Создание или уничтожение CSeleznevLR3View

CSeleznevLR3View::CSeleznevLR3View() noexcept
{
	// TODO: добавьте код создания

}

CSeleznevLR3View::~CSeleznevLR3View()
{
}

BOOL CSeleznevLR3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CSeleznevLR3View

void CSeleznevLR3View::OnDraw(CDC* pDC)
{
	CSeleznevLR3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	CSize all_size = pDoc->Stock.Drawing(pDC);
	SetScrollSizes(MM_TEXT, all_size);
}

void CSeleznevLR3View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

BOOL CSeleznevLR3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}
void CSeleznevLR3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CSeleznevLR3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

// Диагностика CSeleznevLR3View

#ifdef _DEBUG
void CSeleznevLR3View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CSeleznevLR3View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CSeleznevLR3Doc* CSeleznevLR3View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSeleznevLR3Doc)));
	return (CSeleznevLR3Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CSeleznevLR3View
