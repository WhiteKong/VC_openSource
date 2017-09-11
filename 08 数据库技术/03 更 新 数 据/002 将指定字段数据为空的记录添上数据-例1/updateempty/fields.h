#if !defined(AFX_FIELDS_H__E709A7C3_DE12_43F4_9E35_0FA0D53D3D06__INCLUDED_)
#define AFX_FIELDS_H__E709A7C3_DE12_43F4_9E35_0FA0D53D3D06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CField;

/////////////////////////////////////////////////////////////////////////////
// CFields wrapper class

class CFields : public COleDispatchDriver
{
public:
	CFields() {}		// Calls COleDispatchDriver default constructor
	CFields(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFields(const CFields& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	void Refresh();
	CField GetItem(const VARIANT& Index);
	void Delete(const VARIANT& Index);
	void Append(LPCTSTR Name, long Type, long DefinedSize, long Attrib, const VARIANT& FieldValue);
	void Update();
	void Resync(long ResyncValues);
	void CancelUpdate();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIELDS_H__E709A7C3_DE12_43F4_9E35_0FA0D53D3D06__INCLUDED_)
