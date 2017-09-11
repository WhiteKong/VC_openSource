#if !defined(AFX_ADODC_H__326D0C51_EFF9_49DA_A39C_496280152C7B__INCLUDED_)
#define AFX_ADODC_H__326D0C51_EFF9_49DA_A39C_496280152C7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class C_Recordset;
class COleFont;

/////////////////////////////////////////////////////////////////////////////
// CAdodc wrapper class

class CAdodc : public CWnd
{
protected:
	DECLARE_DYNCREATE(CAdodc)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x67397aa3, 0x7fb1, 0x11d0, { 0xb1, 0x48, 0x0, 0xa0, 0xc9, 0x22, 0xe8, 0x20 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	CString GetConnectionString();
	void SetConnectionString(LPCTSTR lpszNewValue);
	CString GetUserName_();
	void SetUserName(LPCTSTR lpszNewValue);
	CString GetPassword();
	void SetPassword(LPCTSTR lpszNewValue);
	long GetMode();
	void SetMode(long nNewValue);
	long GetCursorLocation();
	void SetCursorLocation(long nNewValue);
	long GetConnectionTimeout();
	void SetConnectionTimeout(long nNewValue);
	long GetCommandTimeout();
	void SetCommandTimeout(long nNewValue);
	CString GetRecordSource();
	void SetRecordSource(LPCTSTR lpszNewValue);
	long GetCursorType();
	void SetCursorType(long nNewValue);
	long GetLockType();
	void SetLockType(long nNewValue);
	long GetCommandType();
	void SetCommandType(long nNewValue);
	long GetCacheSize();
	void SetCacheSize(long nNewValue);
	long GetMaxRecords();
	void SetMaxRecords(long nNewValue);
	long GetBOFAction();
	void SetBOFAction(long nNewValue);
	long GetEOFAction();
	void SetEOFAction(long nNewValue);
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	long GetAppearance();
	void SetAppearance(long nNewValue);
	unsigned long GetBackColor();
	void SetBackColor(unsigned long newValue);
	unsigned long GetForeColor();
	void SetForeColor(unsigned long newValue);
	long GetOrientation();
	void SetOrientation(long nNewValue);
	C_Recordset GetRecordset();
	void SetRefRecordset(LPDISPATCH newValue);
	COleFont GetFont();
	void SetRefFont(LPDISPATCH newValue);
	BOOL GetEnabled();
	void SetEnabled(BOOL bNewValue);
	void Refresh();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODC_H__326D0C51_EFF9_49DA_A39C_496280152C7B__INCLUDED_)
