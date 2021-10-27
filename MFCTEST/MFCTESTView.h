#pragma once
class CMFCTESTView : public CView
{
public:
	CMFCTESTDoc* GetDocument() const;
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual int OnCreate(LPCREATESTRUCT lpcs);
	virtual void OnSize(UINT nType, int cx, int cy);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	virtual ~CMFCTESTView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	CMFCTESTView() noexcept;
	DECLARE_DYNCREATE(CMFCTESTView)
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCTESTView.cpp
inline CMFCTESTDoc* CMFCTESTView::GetDocument() const
   { return reinterpret_cast<CMFCTESTDoc*>(m_pDocument); }
#endif

