
#include "pch.h"
#include "framework.h"

#ifndef SHARED_HANDLERS
#include "MFCTEST.h"
#endif
#include "MFCTESTDoc.h"
#include <propkey.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCTESTDoc, CDocument)
BEGIN_MESSAGE_MAP(CMFCTESTDoc, CDocument)
END_MESSAGE_MAP()

CMFCTESTDoc::CMFCTESTDoc() noexcept
{
	// TODO: add one-time construction code here

}

CMFCTESTDoc::~CMFCTESTDoc()
{
}

BOOL CMFCTESTDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	// TODO: add reinitialization code here
	return TRUE;
}

void CMFCTESTDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS
void CMFCTESTDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{

	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

void CMFCTESTDoc::InitializeSearchContent()
{
	CString strSearchContent;
	SetSearchContent(strSearchContent);
}

void CMFCTESTDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif 

#ifdef _DEBUG
void CMFCTESTDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCTESTDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif