#if !defined(AFX__RECORDSET_H__C004CAF2_7626_4F61_B267_E7B759032492__INCLUDED_)
#define AFX__RECORDSET_H__C004CAF2_7626_4F61_B267_E7B759032492__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CProperties;
class CFields;

/////////////////////////////////////////////////////////////////////////////
// C_Recordset wrapper class

class C_Recordset : public COleDispatchDriver
{
public:
	C_Recordset() {}		// Calls COleDispatchDriver default constructor
	C_Recordset(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	C_Recordset(const C_Recordset& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CProperties GetProperties();
	long GetAbsolutePosition();
	void SetAbsolutePosition(long nNewValue);
	void SetRefActiveConnection(LPDISPATCH newValue);
	void SetActiveConnection(const VARIANT& newValue);
	VARIANT GetActiveConnection();
	BOOL GetBof();
	VARIANT GetBookmark();
	void SetBookmark(const VARIANT& newValue);
	long GetCacheSize();
	void SetCacheSize(long nNewValue);
	long GetCursorType();
	void SetCursorType(long nNewValue);
	BOOL GetEof();
	CFields GetFields();
	long GetLockType();
	void SetLockType(long nNewValue);
	long GetMaxRecords();
	void SetMaxRecords(long nNewValue);
	long GetRecordCount();
	void SetRefSource(LPDISPATCH newValue);
	void SetSource(LPCTSTR lpszNewValue);
	VARIANT GetSource();
	void AddNew(const VARIANT& FieldList, const VARIANT& Values);
	void CancelUpdate();
	void Close();
	void Delete(long AffectRecords);
	VARIANT GetRows(long Rows, const VARIANT& Start, const VARIANT& Fields);
	void Move(long NumRecords, const VARIANT& Start);
	void MoveNext();
	void MovePrevious();
	void MoveFirst();
	void MoveLast();
	void Open(const VARIANT& Source, const VARIANT& ActiveConnection, long CursorType, long LockType, long Options);
	void Requery(long Options);
	void Update(const VARIANT& Fields, const VARIANT& Values);
	long GetAbsolutePage();
	void SetAbsolutePage(long nNewValue);
	long GetEditMode();
	VARIANT GetFilter();
	void SetFilter(const VARIANT& newValue);
	long GetPageCount();
	long GetPageSize();
	void SetPageSize(long nNewValue);
	CString GetSort();
	void SetSort(LPCTSTR lpszNewValue);
	long GetStatus();
	long GetState();
	void UpdateBatch(long AffectRecords);
	void CancelBatch(long AffectRecords);
	long GetCursorLocation();
	void SetCursorLocation(long nNewValue);
	C_Recordset NextRecordset(VARIANT* RecordsAffected);
	BOOL Supports(long CursorOptions);
	long GetMarshalOptions();
	void SetMarshalOptions(long nNewValue);
	void Find(LPCTSTR Criteria, long SkipRecords, long SearchDirection, const VARIANT& Start);
	void Cancel();
	LPUNKNOWN GetDataSource();
	void SetRefDataSource(LPUNKNOWN newValue);
	LPDISPATCH GetActiveCommand();
	void SetStayInSync(BOOL bNewValue);
	BOOL GetStayInSync();
	CString GetString(long StringFormat, long NumRows, LPCTSTR ColumnDelimeter, LPCTSTR RowDelimeter, LPCTSTR NullExpr);
	CString GetDataMember();
	void SetDataMember(LPCTSTR lpszNewValue);
	long CompareBookmarks(const VARIANT& Bookmark1, const VARIANT& Bookmark2);
	C_Recordset Clone(long LockType);
	void Resync(long AffectRecords, long ResyncValues);
	void Seek(const VARIANT& KeyValues, long SeekOption);
	void SetIndex(LPCTSTR lpszNewValue);
	CString GetIndex();
	void Save(const VARIANT& Destination, long PersistFormat);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__RECORDSET_H__C004CAF2_7626_4F61_B267_E7B759032492__INCLUDED_)
