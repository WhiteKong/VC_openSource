// HideTrayWndDlg.h : header file
//

#if !defined(AFX_HIDETRAYWNDDLG_H__E1BDF30E_DD2B_40BD_8D0F_88321C2805F7__INCLUDED_)
#define AFX_HIDETRAYWNDDLG_H__E1BDF30E_DD2B_40BD_8D0F_88321C2805F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHideTrayWndDlg dialog

class CHideTrayWndDlg : public CDialog
{
// Construction
public:
	CHideTrayWndDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHideTrayWndDlg)
	enum { IDD = IDD_HIDETRAYWND_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideTrayWndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHideTrayWndDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHide();
	afx_msg void OnShow();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDETRAYWNDDLG_H__E1BDF30E_DD2B_40BD_8D0F_88321C2805F7__INCLUDED_)
