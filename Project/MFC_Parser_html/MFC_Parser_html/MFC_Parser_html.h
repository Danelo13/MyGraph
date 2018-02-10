
// MFC_Parser_html.h : main header file for the MFC_Parser_html application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFC_Parser_htmlApp:
// See MFC_Parser_html.cpp for the implementation of this class
//

class CMFC_Parser_htmlApp : public CWinAppEx
{
public:
	CMFC_Parser_htmlApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_Parser_htmlApp theApp;
