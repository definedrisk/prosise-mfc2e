class CMyApp : public CWinApp
{
public:
    virtual BOOL InitInstance ();
    virtual int ExitInstance();
};

class CMainWindow : public CFrameWnd
{
public:
    CMainWindow ();

    // exmaple structure to cause a leak
    struct BigData {
      int index[3]{1, 2, 3 };
      float data[3]{1.1, 2.2, 3.3 };
    };

protected:
    afx_msg void OnPaint ();
    DECLARE_MESSAGE_MAP ()

private:
  BigData* m_data{ nullptr };
  virtual void PostNcDestroy();
};
