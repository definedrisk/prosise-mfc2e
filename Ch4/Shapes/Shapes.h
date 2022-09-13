// Shapes.h : main header file for the SHAPES application
//

#if !defined(AFX_SHAPES_H__437C8B37_5C45_11D2_8E53_006008A82731__INCLUDED_)
#define AFX_SHAPES_H__437C8B37_5C45_11D2_8E53_006008A82731__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShapesApp:
// See Shapes.cpp for the implementation of this class
//

class CShapesApp : public CWinApp
{
public:
	CShapesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShapesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

public:
	//{{AFX_MSG(CShapesApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAPES_H__437C8B37_5C45_11D2_8E53_006008A82731__INCLUDED_)
