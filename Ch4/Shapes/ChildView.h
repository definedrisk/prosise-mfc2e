// ChildView.h : interface of the CChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDVIEW_H__437C8B3D_5C45_11D2_8E53_006008A82731__INCLUDED_)
#define AFX_CHILDVIEW_H__437C8B3D_5C45_11D2_8E53_006008A82731__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	int m_nShape;
	//{{AFX_MSG(CChildView)
	afx_msg void OnPaint();
	afx_msg void OnShapeCircle();
	afx_msg void OnShapeTriangle();
	afx_msg void OnShapeSquare();
	afx_msg void OnUpdateShapeCircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateShapeTriangle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateShapeSquare(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDVIEW_H__437C8B3D_5C45_11D2_8E53_006008A82731__INCLUDED_)
