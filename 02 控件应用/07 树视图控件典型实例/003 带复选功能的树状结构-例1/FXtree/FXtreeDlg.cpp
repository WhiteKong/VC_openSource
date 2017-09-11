// FXtreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FXtree.h"
#include "FXtreeDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CFXtreeApp theApp;
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
// CFXtreeDlg dialog

CFXtreeDlg::CFXtreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFXtreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFXtreeDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFXtreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFXtreeDlg)
	DDX_Control(pDX, IDC_RICHEDIT1, m_rich);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFXtreeDlg, CDialog)
	//{{AFX_MSG_MAP(CFXtreeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFXtreeDlg message handlers

BOOL CFXtreeDlg::OnInitDialog()
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
	Load_dep();
	m_treeImageList.Create(16,16,ILC_MASK,4,1);
	m_treeImageList.Add(theApp.LoadIcon(IDI_ICON2));
	m_treeImageList.Add(theApp.LoadIcon(IDI_ICON3));
	m_treeImageList.Add(theApp.LoadIcon(IDI_ICON1));
	HICON hIcon=::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
	m_tree.SetImageList(&m_treeImageList,LVSIL_NORMAL);
	m_root=m_tree.InsertItem("青学学院网球部",0,0);
	AddtoTree(m_root,0);
	m_tree.Expand(m_root,TVE_EXPAND);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFXtreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFXtreeDlg::OnPaint() 
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
HCURSOR CFXtreeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFXtreeDlg::AddtoTree(HTREEITEM m_node,int UPID)
{
	HTREEITEM m_child;
	for(int i=0;i<a_upid.GetSize();i++)
	{
		if(UPID==atoi(a_upid.GetAt(i)))
		{
			switch(atoi(a_lx.GetAt(i)))
			{
				case 1:
					m_child = m_tree.InsertItem(a_name.GetAt(i),1,1,m_node);
					AddtoTree(m_child,atoi(a_id.GetAt(i)));
					break;
				case 2:
					m_child = m_tree.InsertItem(a_name.GetAt(i),2,2,m_node);
					AddtoTree(m_child,atoi(a_id.GetAt(i)));
					break;
			}
		}
	}
}

void CFXtreeDlg::Load_dep()
{
	//连接数据库
    ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
    //设置SQL语句
	_bstr_t vSQL;
	vSQL="SELECT*FROM fuxan ORDER BY id";
    _RecordsetPtr m_pRecordset;
    m_pRecordset=m_AdoConn.GetRecordSet(vSQL);
	//初始化数组
	a_id.RemoveAll();
	a_upid.RemoveAll();
	a_lx.RemoveAll();
	a_name.RemoveAll();
	while(m_pRecordset->adoEOF==0)
	{
		a_id.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("id"));
		a_upid.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("upid"));
		a_lx.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("lx"));
		a_name.Add((LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("name"));
		m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
}

void CFXtreeDlg::OnOK() 
{
	// TODO: Add extra validation here
	HTREEITEM item;
	item = m_tree.GetRootItem();
	str="";
	if(m_tree.GetCheck(item)!=0)
	{
		str+=m_tree.GetItemText(item);
		str+="\n";
		m_rich.SetWindowText(str);
	}
	OuttoTree(item);
	//CDialog::OnOK();
}

void CFXtreeDlg::OuttoTree(HTREEITEM m_node)
{
	HTREEITEM m_child;
	m_node = m_tree.GetChildItem(m_node);
	if (m_node != NULL)
	{
		while (m_node!= NULL)
		{
			if(m_tree.GetCheck(m_node)!=0)
			{
				str+=m_tree.GetItemText(m_node);
				str+="\n";
				m_rich.SetWindowText(str);
			}
			m_child = m_node;
			OuttoTree(m_child);
			m_node = m_tree.GetNextItem(m_node,TVGN_NEXT);
		}
	}
}
