// SelectIntoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SelectInto.h"
#include "SelectIntoDlg.h"

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
// CSelectIntoDlg dialog

CSelectIntoDlg::CSelectIntoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectIntoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectIntoDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSelectIntoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectIntoDlg)
	DDX_Control(pDX, IDC_DATAGRID1, m_datagrid);
	DDX_Control(pDX, IDC_ADODC1, m_adodc);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSelectIntoDlg, CDialog)
	//{{AFX_MSG_MAP(CSelectIntoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONCOPY, OnButtoncopy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectIntoDlg message handlers

BOOL CSelectIntoDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSelectIntoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSelectIntoDlg::OnPaint() 
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
HCURSOR CSelectIntoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSelectIntoDlg::OnButtoncopy() 
{
	// TODO: Add your control notification handler code here
	m_datagrid.SetCaption("具有销售表结构的新表：copyframe");
	OnInitADOConn();
	_bstr_t vSQL;
	vSQL="select * into copyframe from xiaoshoubiao where 书号 = NULL";
	ExecuteSQL(vSQL);
	ExitConnect();
	m_adodc.SetRecordSource("select * from copyframe");
	m_adodc.Refresh();
}

void CSelectIntoDlg::OnInitADOConn()
{
	try
	{
       m_pConnection.CreateInstance("ADODB.Connection");
	   _bstr_t strConnect="Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=Shujuku;Data Source=.";
	   m_pConnection->Open(strConnect,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

BOOL CSelectIntoDlg::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
        if(m_pConnection==NULL)
	     	OnInitADOConn();
        m_pConnection->Execute(bstrSQL,NULL,adCmdText);
		return true;
	}
	catch(_com_error e)
	{
		e.Description();
		return false;
	}
}

void CSelectIntoDlg::ExitConnect()
{
	if(m_pRecordset!=NULL)
		m_pRecordset->Close();
	m_pConnection->Close();
}
