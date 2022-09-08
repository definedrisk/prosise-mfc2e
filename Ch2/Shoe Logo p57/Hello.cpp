#include <afxwin.h>
#include <math.h>
#include "Hello.h"

#define SEGMENTS 500
#define PI 3.1415926

CMyApp myApp;

/////////////////////////////////////////////////////////////////////////
// CMyApp member functions

BOOL CMyApp::InitInstance ()
{
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
    Create (NULL, _T ("The Hello Application"));
}

void CMainWindow::OnPaint ()
{
    CRect rect;
    GetClientRect(&rect);
    int nWidth = rect.Width();
    int nHeight = rect.Height();

    CPaintDC dc (this);

    /*dc.DrawText (_T ("Hello, MFC"), -1, &rect,
    DT_SINGLELINE | DT_CENTER | DT_VCENTER);*/

    /*CPoint aPoint[SEGMENTS];
    for (int i = 0; i < SEGMENTS; i++)
    {
        aPoint[i].x = (i * nWidth) / SEGMENTS;
        aPoint[i].y = (int)((nHeight / 2) * (1 - (sin((2 * PI * i) / SEGMENTS))));
    }
    dc.Polyline(aPoint, SEGMENTS);*/

    POINT aPoint1[4] = { 120,100,120,200,250,150,500,40 };
    POINT aPoint2[4] = { 120,100,50,350,250,200,500,40 };
    dc.PolyBezier(aPoint1, 4);
    dc.PolyBezier(aPoint2, 4);


}
