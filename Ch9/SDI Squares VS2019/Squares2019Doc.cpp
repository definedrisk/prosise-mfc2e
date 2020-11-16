
// Squares2019Doc.cpp : implementation of the CSquares2019Doc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SDI Squares VS2019.h"
#endif

#include "Squares2019Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSquares2019Doc

IMPLEMENT_DYNCREATE(CSquares2019Doc, CDocument)

BEGIN_MESSAGE_MAP(CSquares2019Doc, CDocument)
	ON_COMMAND(ID_COLOR_RED, &CSquares2019Doc::OnColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CSquares2019Doc::OnUpdateColorRed)
	ON_COMMAND(ID_COLOR_BLUE, &CSquares2019Doc::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CSquares2019Doc::OnUpdateColorBlue)
	ON_COMMAND(ID_COLOR_CYAN, &CSquares2019Doc::OnColorCyan)
	ON_UPDATE_COMMAND_UI(ID_COLOR_CYAN, &CSquares2019Doc::OnUpdateColorCyan)
	ON_COMMAND(ID_COLOR_GREEN, &CSquares2019Doc::OnColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CSquares2019Doc::OnUpdateColorGreen)
	ON_COMMAND(ID_COLOR_WHITE, &CSquares2019Doc::OnColorWhite)
	ON_UPDATE_COMMAND_UI(ID_COLOR_WHITE, &CSquares2019Doc::OnUpdateColorWhite)
	ON_COMMAND(ID_COLOR_YELLOW, &CSquares2019Doc::OnColorYellow)
	ON_UPDATE_COMMAND_UI(ID_COLOR_YELLOW, &CSquares2019Doc::OnUpdateColorYellow)
END_MESSAGE_MAP()


// CSquares2019Doc construction/destruction

CSquares2019Doc::CSquares2019Doc() noexcept
{
	// TODO: add one-time construction code here

}

CSquares2019Doc::~CSquares2019Doc()
{
}

BOOL CSquares2019Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			m_clrGrid[i][j] = RGB(255, 255, 255);

	m_clrCurrentColor = RGB(255, 0, 0);

	return TRUE;
}




// CSquares2019Doc serialization

void CSquares2019Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				ar << m_clrGrid[i][j];
		ar << m_clrCurrentColor;
	}
	else
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				ar >> m_clrGrid[i][j];
		ar >> m_clrCurrentColor;
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CSquares2019Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
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

// Support for Search Handlers
void CSquares2019Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSquares2019Doc::SetSearchContent(const CString& value)
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

#endif // SHARED_HANDLERS

// CSquares2019Doc diagnostics

#ifdef _DEBUG
void CSquares2019Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSquares2019Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSquares2019Doc commands


COLORREF CSquares2019Doc::GetCurrentColor()
{
	// TODO: Add your implementation code here.
	return m_clrCurrentColor;
}


COLORREF CSquares2019Doc::GetSquare(int i, int j)
{
	// TODO: Add your implementation code here.
	ASSERT(i >= 0 && i <= 3 && j >= 0 && j <= 3);
#pragma warning(suppress : 6385)
	return m_clrGrid[i][j];
}


void CSquares2019Doc::SetSquare(int i, int j, COLORREF color)
{
	// TODO: Add your implementation code here.
	ASSERT(i >= 0 && i <= 3 && j >= 0 && j <= 3);
#pragma warning(suppress : 6386)
	m_clrGrid[i][j] = color;
	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}


void CSquares2019Doc::OnColorRed()
{
	// TODO: Add your command handler code here
	m_clrCurrentColor = RGB(255, 0, 0);
}


void CSquares2019Doc::OnUpdateColorRed(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255, 0, 0));
}


void CSquares2019Doc::OnColorBlue()
{
	// TODO: Add your command handler code here
	m_clrCurrentColor = RGB(0, 0, 255);
}


void CSquares2019Doc::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0, 0, 255));
}


void CSquares2019Doc::OnColorCyan()
{
	// TODO: Add your command handler code here
	m_clrCurrentColor = RGB(0, 255, 255);
}


void CSquares2019Doc::OnUpdateColorCyan(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0, 255, 255));
}


void CSquares2019Doc::OnColorGreen()
{
	// TODO: Add your command handler code here
	m_clrCurrentColor = RGB(0, 255, 0);
}


void CSquares2019Doc::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0, 255, 0));
}


void CSquares2019Doc::OnColorWhite()
{
	// TODO: Add your command handler code here
	m_clrCurrentColor = RGB(255, 255, 255);
}


void CSquares2019Doc::OnUpdateColorWhite(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255, 255, 255));
}


void CSquares2019Doc::OnColorYellow()
{
	// TODO: Add your command handler code here
	m_clrCurrentColor = RGB(255, 255, 0);
}


void CSquares2019Doc::OnUpdateColorYellow(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255, 255, 0));
}
