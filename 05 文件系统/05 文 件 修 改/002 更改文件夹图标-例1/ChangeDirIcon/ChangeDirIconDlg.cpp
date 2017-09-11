// ChangeDirIconDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeDirIcon.h"
#include "ChangeDirIconDlg.h"

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
// CChangeDirIconDlg dialog

CChangeDirIconDlg::CChangeDirIconDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeDirIconDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeDirIconDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeDirIconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeDirIconDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChangeDirIconDlg, CDialog)
	//{{AFX_MSG_MAP(CChangeDirIconDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTADD, OnAdd)
	ON_BN_CLICKED(IDC_BTSEL, OnSel)
	ON_BN_CLICKED(IDC_BTMODIFY, OnModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeDirIconDlg message handlers

BOOL CChangeDirIconDlg::OnInitDialog()
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

void CChangeDirIconDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChangeDirIconDlg::OnPaint() 
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
HCURSOR CChangeDirIconDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChangeDirIconDlg::OnAdd() 
{
	BROWSEINFO bi;   
	char buffer[MAX_PATH];   
	ZeroMemory(buffer,MAX_PATH);   
	bi.hwndOwner=GetSafeHwnd();   
	bi.pidlRoot=NULL;   
	bi.pszDisplayName=buffer;   
	bi.lpszTitle="选择一个文件夹";   
	bi.ulFlags=BIF_EDITBOX;   
	bi.lpfn=NULL;   
	bi.lParam=0;   
	bi.iImage=0; 
	LPITEMIDLIST pList=NULL;   
	if((pList=SHBrowseForFolder(&bi))!=NULL)   
	{   
		char path[MAX_PATH];   
		ZeroMemory(path,MAX_PATH);   
		SHGetPathFromIDList(pList,path);   
		GetDlgItem(IDC_EDSELDIR)->SetWindowText(path); 
		SHFILEINFO shfile;
		despath=path;
		strcat(path,"\\");
		::SHGetFileInfo(path,0,&shfile,sizeof(shfile),SHGFI_ICON);
		CStatic*pStatic = (CStatic*)GetDlgItem(IDC_DIR);
	        pStatic->SetIcon(shfile.hIcon);
	} 
  
}	


void CChangeDirIconDlg::OnSel() 
{
	CFileDialog fileDialog( TRUE,"*.ICO",NULL,NULL,"资源文件(*.ICO,*.BMP,*.EXE,*.DLL,*.ICL)|*.ICO;*.BMP;*.EXE;*.DLL;*.ICL||");
	if(fileDialog.DoModal()==IDOK) 
	{
		strpath=fileDialog.GetPathName();
		desname=fileDialog.GetFileName();
        extname= fileDialog.GetFileExt();
		extname.MakeLower();
	}
        if(extname =="ico") 
		{
			lpIR=pIcons->ReadIconFromICOFile(strpath);		
			HICON hIcon;
			hIcon=ExtractIcon(AfxGetInstanceHandle(),strpath,0);
			CStatic*pStatic = (CStatic*)GetDlgItem(IDC_DES);
	        pStatic->SetIcon(hIcon);
		}	
}

void CChangeDirIconDlg::OnModify() 
{
	CString temp,temp2;
	SetFileAttributes(despath,FILE_ATTRIBUTE_READONLY);
	temp=despath;
	temp+="\\";
	temp+=desname;
	if(CopyFile(strpath,temp,FALSE))
	{AfxMessageBox("成功");}
	else
	{AfxMessageBox("失败");}
	temp2=despath;
	temp2+="\\";
	temp2+="desktop.ini";
	::WritePrivateProfileString(".ShellClassInfo","IconFile",desname,temp2);
	::WritePrivateProfileString(".ShellClassInfo","IconIndex","0",temp2);	
	
}
