
// MFC_Parser_htmlView.cpp : implementation of the CMFC_Parser_htmlView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFC_Parser_html.h"
#endif

#include "MFC_Parser_htmlDoc.h"
#include "MFC_Parser_htmlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_Parser_htmlView

IMPLEMENT_DYNCREATE(CMFC_Parser_htmlView, CView)

BEGIN_MESSAGE_MAP(CMFC_Parser_htmlView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFC_Parser_htmlView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFC_Parser_htmlView construction/destruction

CMFC_Parser_htmlView::CMFC_Parser_htmlView()
{
	// TODO: add construction code here

}

CMFC_Parser_htmlView::~CMFC_Parser_htmlView()
{
}

BOOL CMFC_Parser_htmlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFC_Parser_htmlView drawing

void CMFC_Parser_htmlView::OnDraw(CDC* /*pDC*/)
{
	CMFC_Parser_htmlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFC_Parser_htmlView printing


void CMFC_Parser_htmlView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFC_Parser_htmlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFC_Parser_htmlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFC_Parser_htmlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFC_Parser_htmlView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFC_Parser_htmlView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFC_Parser_htmlView diagnostics

#ifdef _DEBUG
void CMFC_Parser_htmlView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_Parser_htmlView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_Parser_htmlDoc* CMFC_Parser_htmlView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_Parser_htmlDoc)));
	return (CMFC_Parser_htmlDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_Parser_htmlView message handlers
