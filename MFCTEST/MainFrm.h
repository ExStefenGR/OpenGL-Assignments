#pragma once
class CMainFrame : public CFrameWnd
{
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

};