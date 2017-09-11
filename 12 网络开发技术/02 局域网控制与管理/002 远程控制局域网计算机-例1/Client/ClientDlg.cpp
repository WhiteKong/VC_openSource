// ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"

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
// CClientDlg dialog

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDlg)
	m_name = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDlg)
	DDX_Text(pDX, IDC_EDIT1, m_name);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDlg, CDialog)
	//{{AFX_MSG_MAP(CClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTHIDE, OnButhide)
	ON_BN_CLICKED(IDC_BUTSHOW, OnButshow)
	ON_BN_CLICKED(IDC_BUTLOGOUT, OnButlogout)
	ON_BN_CLICKED(IDC_BUTCLOSE, OnButclose)
	ON_BN_CLICKED(IDC_BUTREBOOT, OnButreboot)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDlg message handlers

BOOL CClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_client = socket(AF_INET,SOCK_STREAM,0);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientDlg::OnPaint() 
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
HCURSOR CClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CClientDlg::LianJie()
{
	UpdateData(true);
	CString str="";
	struct hostent * pHost;
	pHost = gethostbyname(m_name);
	if(pHost==NULL)
	{
		MessageBox("无法获得IP地址");
		return;
	}
	else
	{
		for(int n=0;n<4;n++)
		{
			CString addr;
			if(n > 0)
			{
				str += ".";
			}
			addr.Format("%u",(unsigned int)((unsigned char*)pHost->h_addr_list[0])[n]);
			str += addr;
		}
	}
	//服务器端地址
	sockaddr_in serveraddr;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(70);
	serveraddr.sin_addr.S_un.S_addr = inet_addr(str);
	connect(m_client,(sockaddr*)&serveraddr,sizeof(serveraddr));
	WSAAsyncSelect(m_client,m_hWnd,1000,FD_READ);
}

void CClientDlg::OnButhide() 
{
	// TODO: Add your control notification handler code here
	LianJie();
	CString info;
	info="1";
	int i = send(m_client,info.GetBuffer(0),info.GetLength(),0);
}

void CClientDlg::OnButshow() 
{
	// TODO: Add your control notification handler code here
	LianJie();
	CString info;
	info="2";
	//开始发送数据
	int i = send(m_client,info.GetBuffer(0),info.GetLength(),0);
}

void CClientDlg::OnButlogout() 
{
	// TODO: Add your control notification handler code here
	LianJie();
	CString info;
	info="3";
	//开始发送数据
	int i = send(m_client,info.GetBuffer(0),info.GetLength(),0);
}

void CClientDlg::OnButclose() 
{
	// TODO: Add your control notification handler code here
	LianJie();
	CString info;
	info="4";
	//开始发送数据
	int i = send(m_client,info.GetBuffer(0),info.GetLength(),0);
}

void CClientDlg::OnButreboot() 
{
	// TODO: Add your control notification handler code here
	LianJie();
	CString info;
	info="5";
	//开始发送数据
	int i = send(m_client,info.GetBuffer(0),info.GetLength(),0);
}
