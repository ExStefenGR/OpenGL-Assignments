#include "framework.h"
#ifndef SHARED_HANDLERS
#include "MFCTEST.h"
#endif

#include "MFCTESTDoc.h"
#include "MFCTESTView.h"
#include "Screen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
IMPLEMENT_DYNCREATE(CMFCTESTView, CView)
BEGIN_MESSAGE_MAP(CMFCTESTView, CView)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	
	ON_WM_CREATE()
	ON_WM_SIZE()
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
	Screen::Instance()->Refresh();
	Screen::Instance()->Present();
	// TODO: add draw code for native data here
}

int CMFCTESTView::OnCreate(LPCREATESTRUCT lpcs)
{
	if (CView::OnCreate(lpcs) == -1)
	{
		return -1;
	}

	if(!Screen::Instance()->Initialize(GetSafeHwnd()))
	{
		return -1;
	}
	ModifyStyleEx(WS_EX_CLIENTEDGE, 0);

	return 1;
}

void CMFCTESTView::OnSize(UINT nType, int width, int height)
{
	Screen::Instance()->SetViewport(0, 0, width, height);
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