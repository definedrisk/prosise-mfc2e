
// Squares2019View.h : interface of the CSquares2019View class
//

#pragma once

#define USESCROLLVIEW

#ifdef USESCROLLVIEW
class CSquares2019View : public CScrollView
{
protected: // create from serialization only
	CSquares2019View() noexcept;
	DECLARE_DYNCREATE(CSquares2019View)

	// Attributes
public:
	CSquares2019Doc* GetDocument() const;

	// Operations
public:

	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// Implementation
public:
	virtual ~CSquares2019View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
};
#else
class CSquares2019View : public CView
{
protected: // create from serialization only
	CSquares2019View() noexcept;
	DECLARE_DYNCREATE(CSquares2019View)

// Attributes
public:
	CSquares2019Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CSquares2019View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
#endif

#ifndef _DEBUG  // debug version in Squares2019View.cpp
inline CSquares2019Doc* CSquares2019View::GetDocument() const
   { return reinterpret_cast<CSquares2019Doc*>(m_pDocument); }
#endif

