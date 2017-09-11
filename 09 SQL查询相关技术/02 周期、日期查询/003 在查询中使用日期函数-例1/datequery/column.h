#if !defined(AFX_COLUMN_H__056BD9CB_DF3A_47F1_BFF0_C8A825181270__INCLUDED_)
#define AFX_COLUMN_H__056BD9CB_DF3A_47F1_BFF0_C8A825181270__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CDataFormatDisp;

/////////////////////////////////////////////////////////////////////////////
// CColumn wrapper class

class CColumn : public COleDispatchDriver
{
public:
	CColumn() {}		// Calls COleDispatchDriver default constructor
	CColumn(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CColumn(const CColumn& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetAlignment();
	void SetAlignment(long nNewValue);
	BOOL GetAllowSizing();
	void SetAllowSizing(BOOL bNewValue);
	BOOL GetButton();
	void SetButton(BOOL bNewValue);
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	short GetColIndex();
	BOOL GetDataChanged();
	CString GetDataField();
	void SetDataField(LPCTSTR lpszNewValue);
	long GetDividerStyle();
	void SetDividerStyle(long nNewValue);
	float GetLeft();
	BOOL GetLocked();
	void SetLocked(BOOL bNewValue);
	CString GetNumberFormat();
	void SetNumberFormat(LPCTSTR lpszNewValue);
	CString GetText();
	void SetText(LPCTSTR lpszNewValue);
	float GetTop();
	VARIANT GetValue();
	void SetValue(const VARIANT& newValue);
	BOOL GetVisible();
	void SetVisible(BOOL bNewValue);
	float GetWidth();
	void SetWidth(float newValue);
	BOOL GetWrapText();
	void SetWrapText(BOOL bNewValue);
	CDataFormatDisp GetDataFormat();
	void SetRefDataFormat(LPDISPATCH newValue);
	CString CellText(const VARIANT& Bookmark);
	VARIANT CellValue(const VARIANT& Bookmark);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLUMN_H__056BD9CB_DF3A_47F1_BFF0_C8A825181270__INCLUDED_)
