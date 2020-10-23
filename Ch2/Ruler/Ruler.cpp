#include <afxwin.h>
#include "Ruler.h"

#define LEAK

// Tracking memory allocations in MFC
#ifdef _DEBUG
#define new DEBUG_NEW
/*
Detected memory leaks!
...
Dumping objects ->
D:\source\repos\definedrisk\prosise-mfc2e\Ch2\Ruler\Ruler.cpp(53) : {170} normal block at 0x00B29FC8, 8000 bytes long.
 Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
Object dump complete.
...

Without #define new DEBUG_NEW the output would be:

Detected memory leaks!
Dumping objects ->
...
{170} normal block at 0x009D8588, 8000 bytes long.
 Data: <                > CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD CD
Object dump complete.
...
*/
#endif

/*
Use BOOL AfxEnableMemoryTracking(BOOL bTrack); to switch the memory tracking feature on and off.
The previous state is returned. Default is on. Turning off will speed up the program when running
in debug configuration.

Use CMemoryState Structure as demonstrated below to report on memory states.
*/

static CMemoryState oldstate, newstate, diffstate;

CMyApp myApp;

/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL CMyApp::InitInstance ()
{
  //note that UNICODE
  TRACE("Example message from __func__: %s\n", __func__);
  TRACE("Example message from __FUNCSIG__: %s\n", __FUNCSIG__);
  TRACE("Example message from __FUNCTION__: %s\n", __FUNCTION__);
  TRACE(_T("Example message UNICODE from __FUNCTIONW__: %s\n"), __FUNCTIONW__);

  oldstate.Checkpoint();

    m_pMainWnd = new CMainWindow;
    m_pMainWnd->ShowWindow (m_nCmdShow);
    m_pMainWnd->UpdateWindow ();
    return TRUE;
}

/////////////////////////////////////////////////////////////////////////
// CMainWindow message map and member functions

BEGIN_MESSAGE_MAP (CMainWindow, CFrameWnd)
    ON_WM_PAINT ()
END_MESSAGE_MAP ()

CMainWindow::CMainWindow ()
{
    Create (NULL, _T ("Ruler"));

    // Aquire resource without delete to generate a memory leak
    if (!m_data) { m_data = new BigData; }
}

void CMainWindow::OnPaint ()
{
    CPaintDC dc (this);
    
    //
    // Initialize the device context.
    //
    dc.SetMapMode (MM_LOENGLISH);
    dc.SetTextAlign (TA_CENTER | TA_BOTTOM);
    dc.SetBkMode (TRANSPARENT);

    //
    // Draw the body of the ruler.
    //
    CBrush brush (RGB (255, 255, 0));
    CBrush* pOldBrush = dc.SelectObject (&brush);
    dc.Rectangle (100, -100, 1300, -200);
    dc.SelectObject (pOldBrush);

    //
    // Draw the tick marks and labels.
    //
    for (int i=125; i<1300; i+=25) {
        dc.MoveTo (i, -192);
        dc.LineTo (i, -200);
    }

    for (int i=150; i<1300; i+=50) {
        dc.MoveTo (i, -184);
        dc.LineTo (i, -200);
    }

    for (int i=200; i<1300; i+=100) {
        dc.MoveTo (i, -175);
        dc.LineTo (i, -200);

        CString string;
        string.Format (_T ("%d"), (i / 100) - 1);
        dc.TextOut (i, -175, string);
    }
}


int CMyApp::ExitInstance()
{
  newstate.Checkpoint();
  //if (diffstate.Difference(oldstate, newstate))
  //{
  diffstate.Difference(oldstate, newstate);
    TRACE("Example message from __FUNCSIG__: %s\n", __FUNCSIG__);
    TRACE(_T("diffstate.DumpStatistics():\n"));
    diffstate.DumpStatistics();
  //}

  return CWinApp::ExitInstance();
}


void CMainWindow::PostNcDestroy()
{
#ifndef LEAK
  delete m_data;
#endif

  CFrameWnd::PostNcDestroy();
}
