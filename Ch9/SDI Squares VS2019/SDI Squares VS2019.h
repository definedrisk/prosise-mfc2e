
// SDI Squares VS2019.h : main header file for the SDI Squares VS2019 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSquares2019App:
// See SDI Squares VS2019.cpp for the implementation of this class
//

class CSquares2019App : public CWinApp
{
public:
	CSquares2019App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSquares2019App theApp;
