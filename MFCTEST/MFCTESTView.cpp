#include "pch.h"
#include "framework.h"
#ifndef SHARED_HANDLERS
#include "MFCTEST.h"
#endif

#include "MFCTESTDoc.h"
#include "MFCTESTView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
IMPLEMENT_DYNCREATE(CMFCTESTView, CView)
BEGIN_MESSAGE_MAP(CMFCTESTView, CView)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

CMFCTESTView::CMFCTESTView() noexcept
{
	// TODO: add construction code here
}

CMFCTESTView::~CMFCTESTView()
{
}

BOOL CMFCTESTView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	return CView::PreCreateWindow(cs);
}

void CMFCTESTView::OnDraw(CDC* /*pDC*/)
{
	CMFCTESTDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here
}

BOOL CMFCTESTView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CMFCTESTView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCTESTView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

#ifdef _DEBUG
void CMFCTESTView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCTESTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCTESTDoc* CMFCTESTView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCTESTDoc)));
	return (CMFCTESTDoc*)m_pDocument;
}
#endif