
// Squares2019View.cpp : implementation of the CSquares2019View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDI Squares VS2019.h"
#endif

#include "Squares2019Doc.h"
#include "Squares2019View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSquares2019View

#ifdef USESCROLLVIEW
IMPLEMENT_DYNCREATE(CSquares2019View, CScrollView)

BEGIN_MESSAGE_MAP(CSquares2019View, CScrollView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
#else
IMPLEMENT_DYNCREATE(CSquares2019View, CView)

BEGIN_MESSAGE_MAP(CSquares2019View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()
#endif

// CSquares2019View construction/destruction

CSquares2019View::CSquares2019View() noexcept
{
	// TODO: add construction code here

}

CSquares2019View::~CSquares2019View()
{
}

BOOL CSquares2019View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSquares2019View drawing

void CSquares2019View::OnDraw(CDC* pDC)
{
	CSquares2019Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	// Set the mapping mode to MM_LOENGLISH.
	//
#ifndef USESCROLLVIEW
	pDC->SetMapMode(MM_LOENGLISH);
#endif

	//
	// Draw the 16 squares.
	//
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			COLORREF color = pDoc->GetSquare(i, j);
			CBrush brush(color);
			int x1 = (j * 100) + 50;
			int y1 = (i * -100) - 50;
			int x2 = x1 + 100;
			int y2 = y1 - 100;
			CRect rect(x1, y1, x2, y2);
			pDC->FillRect(rect, &brush);
		}
	}

	//
	// Then the draw the grid lines surrounding them.
	//
	for (int x = 50; x <= 450; x += 100) {
		pDC->MoveTo(x, -50);
		pDC->LineTo(x, -450);
	}

	for (int y = -50; y >= -450; y -= 100) {
		pDC->MoveTo(50, y);
		pDC->LineTo(450, y);
	}
}


// CSquares2019View diagnostics

#ifdef _DEBUG
void CSquares2019View::AssertValid() const
{
	CView::AssertValid();
}

void CSquares2019View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSquares2019Doc* CSquares2019View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSquares2019Doc)));
	return (CSquares2019Doc*)m_pDocument;
}
#endif //_DEBUG


// CSquares2019View message handlers


void CSquares2019View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
		//
	// Convert to click coordinates to MM_LOENGLISH units.
	//
	CClientDC dc(this);
#ifdef USESCROLLVIEW
	OnPrepareDC(&dc);
#else
	dc.SetMapMode(MM_LOENGLISH);
#endif
	CPoint pos = point;
	dc.DPtoLP(&pos);

	//
	// If a square was clicked, set its color to the current color.
	//
	if (pos.x >= 50 && pos.x <= 450 && pos.y <= -50 && pos.y >= -450) {
		int i = (-pos.y - 50) / 100;
		int j = (pos.x - 50) / 100;
		CSquares2019Doc* pDoc = GetDocument();
		COLORREF clrCurrentColor = pDoc->GetCurrentColor();
		pDoc->SetSquare(i, j, clrCurrentColor);
	}

	CView::OnLButtonDown(nFlags, point);

}


void CSquares2019View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
	SetScrollSizes(MM_LOENGLISH, CSize(500, 500), CSize(200, 200), CSize(50, 50));
}
