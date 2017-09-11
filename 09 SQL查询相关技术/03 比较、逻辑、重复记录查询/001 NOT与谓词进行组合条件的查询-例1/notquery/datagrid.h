#if !defined(AFX_DATAGRID_H__35CBA137_ECB1_46BD_BF2F_01213F50696A__INCLUDED_)
#define AFX_DATAGRID_H__35CBA137_ECB1_46BD_BF2F_01213F50696A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class COleFont;
class CStdDataFormatsDisp;
class CPicture;
class CColumns;
class CSelBookmarks;
class CSplits;

/////////////////////////////////////////////////////////////////////////////
// CDataGrid wrapper class

class CDataGrid : public CWnd
{
protected:
	DECLARE_DYNCREATE(CDataGrid)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xcde57a43, 0x8b86, 0x11d0, { 0xb3, 0xc6, 0x0, 0xa0, 0xc9, 0xa, 0xea, 0x82 } };
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
	long GetAddNewMode();
	BOOL GetAllowAddNew();
	void SetAllowAddNew(BOOL bNewValue);
	BOOL GetAllowArrows();
	void SetAllowArrows(BOOL bNewValue);
	BOOL GetAllowDelete();
	void SetAllowDelete(BOOL bNewValue);
	BOOL GetAllowRowSizing();
	void SetAllowRowSizing(BOOL bNewValue);
	BOOL GetAllowUpdate();
	void SetAllowUpdate(BOOL bNewValue);
	long GetAppearance();
	void SetAppearance(long nNewValue);
	long GetApproxCount();
	unsigned long GetBackColor();
	void SetBackColor(unsigned long newValue);
	VARIANT GetBookmark();
	void SetBookmark(const VARIANT& newValue);
	long GetBorderStyle();
	void SetBorderStyle(long nNewValue);
	CString GetCaption();
	void SetCaption(LPCTSTR lpszNewValue);
	short GetCol();
	void SetCol(short nNewValue);
	BOOL GetColumnHeaders();
	void SetColumnHeaders(BOOL bNewValue);
	BOOL GetCurrentCellModified();
	void SetCurrentCellModified(BOOL bNewValue);
	BOOL GetCurrentCellVisible();
	void SetCurrentCellVisible(BOOL bNewValue);
	BOOL GetDataChanged();
	void SetDataChanged(BOOL bNewValue);
	LPUNKNOWN GetDataSource();
	void SetRefDataSource(LPUNKNOWN newValue);
	CString GetDataMember();
	void SetDataMember(LPCTSTR lpszNewValue);
	float GetDefColWidth();
	void SetDefColWidth(float newValue);
	BOOL GetEditActive();
	void SetEditActive(BOOL bNewValue);
	BOOL GetEnabled();
	void SetEnabled(BOOL bNewValue);
	CString GetErrorText();
	COleFont GetFont();
	void SetRefFont(LPDISPATCH newValue);
	unsigned long GetForeColor();
	void SetForeColor(unsigned long newValue);
	VARIANT GetFirstRow();
	void SetFirstRow(const VARIANT& newValue);
	COleFont GetHeadFont();
	void SetRefHeadFont(LPDISPATCH newValue);
	float GetHeadLines();
	void SetHeadLines(float newValue);
	long GetHWnd();
	long GetHWndEditor();
	short GetLeftCol();
	void SetLeftCol(short nNewValue);
	long GetMarqueeStyle();
	void SetMarqueeStyle(long nNewValue);
	BOOL GetRecordSelectors();
	void SetRecordSelectors(BOOL bNewValue);
	BOOL GetRightToLeft();
	void SetRightToLeft(BOOL bNewValue);
	short GetRow();
	void SetRow(short nNewValue);
	long GetRowDividerStyle();
	void SetRowDividerStyle(long nNewValue);
	float GetRowHeight();
	void SetRowHeight(float newValue);
	long GetScrollBars();
	void SetScrollBars(long nNewValue);
	short GetSelEndCol();
	void SetSelEndCol(short nNewValue);
	long GetSelLength();
	void SetSelLength(long nNewValue);
	long GetSelStart();
	void SetSelStart(long nNewValue);
	short GetSelStartCol();
	void SetSelStartCol(short nNewValue);
	CString GetSelText();
	void SetSelText(LPCTSTR lpszNewValue);
	short GetSplit();
	void SetSplit(short nNewValue);
	BOOL GetTabAcrossSplits();
	void SetTabAcrossSplits(BOOL bNewValue);
	long GetTabAction();
	void SetTabAction(long nNewValue);
	CString GetText();
	void SetText(LPCTSTR lpszNewValue);
	short GetVisibleCols();
	short GetVisibleRows();
	BOOL GetWrapCellPointer();
	void SetWrapCellPointer(BOOL bNewValue);
	CStdDataFormatsDisp GetDataFormats();
	CPicture CaptureImage();
	void ClearSelCols();
	void ClearFields();
	short ColContaining(float X);
	CColumns GetColumns();
	VARIANT GetBookmark(long RowNum);
	void HoldFields();
	void ReBind();
	void Refresh();
	VARIANT RowBookmark(short RowNum);
	short RowContaining(float Y);
	float RowTop(short RowNum);
	void Scroll(long Cols, long Rows);
	CSelBookmarks GetSelBookmarks();
	short SplitContaining(float X, float Y);
	CSplits GetSplits();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAGRID_H__35CBA137_ECB1_46BD_BF2F_01213F50696A__INCLUDED_)
