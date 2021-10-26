#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h" 

class CMFCTESTApp : public CWinApp
{
public:
	CMFCTESTApp() noexcept;
	virtual BOOL InitInstance();
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCTESTApp theApp;
