// TrayPopMenuDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TrayPopMenu.h"
#include "TrayPopMenuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrayPopMenuDlg dialog

CTrayPopMenuDlg::CTrayPopMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrayPopMenuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrayPopMenuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrayPopMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrayPopMenuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTrayPopMenuDlg, CDialog)
	//{{AFX_MSG_MAP(CTrayPopMenuDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_TRARMESSAGE,OnTrayMessage)
	ON_COMMAND(ID_MENUITEMEXIT, OnMenuitemexit)
	ON_WM_MEASUREITEM()
	ON_WM_DRAWITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrayPopMenuDlg message handlers

BOOL CTrayPopMenuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_menu.LoadMenu(IDR_TRAYMENU);
	m_menu.ChangeMenuItem(&m_menu);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_traydata.cbSize = sizeof(NOTIFYICONDATA);
	m_traydata.hIcon = AfxGetApp()->LoadIcon(IDI_TRAYICON);


	m_traydata.hWnd = m_hWnd;

	char  *m_str = "系统管理";
	strncpy(m_traydata.szTip,m_str,strlen(m_str)+1);//strlen +1表示将空字符拷贝到目标字符串中
	m_traydata.uCallbackMessage = WM_TRARMESSAGE;
	m_traydata.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTrayPopMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if ((nID & 0xFFF0) == SC_MINIMIZE )
	{

		ShowWindow(SW_HIDE);
		Shell_NotifyIcon(NIM_ADD,&m_traydata);

	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrayPopMenuDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrayPopMenuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTrayPopMenuDlg::OnOK() 
{
	
//	CDialog::OnOK();
}
void CTrayPopMenuDlg::OnTrayMessage(WPARAM wParam, LPARAM lParam)
{
	if (lParam == WM_LBUTTONDOWN)
	{
		ShowWindow(SW_RESTORE);
	}
	else if (lParam == WM_RBUTTONDOWN)
	{
		CPoint m_point;
		::GetCursorPos(&m_point);
		CIconMenu* m_submenu = (CIconMenu*)m_menu.GetSubMenu(0);
		m_submenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, m_point.x,m_point.y,AfxGetApp()->m_pMainWnd,TPM_LEFTALIGN);
	}
}
void CTrayPopMenuDlg::OnCancel()
{
	if(MessageBox("确定要退出吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION)!=1)
		return;
	//添加系统托盘
	Shell_NotifyIcon(NIM_DELETE,&m_traydata);
	CDialog::OnCancel();
}

BOOL CTrayPopMenuDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{

	return CDialog::OnCommand(wParam, lParam);
}

void CTrayPopMenuDlg::OnMenuitemexit() 
{
	OnCancel();	
}

void CTrayPopMenuDlg::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	m_menu.MeasureItem(lpMeasureItemStruct);	
	//CDialog::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}

void CTrayPopMenuDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	m_menu.DrawItem(lpDrawItemStruct);
	//CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
