#if !defined(AFX_FIELD_H__17A4856A_3263_4CC3_BAD8_A960AE60369E__INCLUDED_)
#define AFX_FIELD_H__17A4856A_3263_4CC3_BAD8_A960AE60369E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CProperties;

/////////////////////////////////////////////////////////////////////////////
// CField wrapper class

class CField : public COleDispatchDriver
{
public:
	CField() {}		// Calls COleDispatchDriver default constructor
	CField(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CField(const CField& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CProperties GetProperties();
	long GetActualSize();
	long GetAttributes();
	long GetDefinedSize();
	CString GetName();
	long GetType();
	VARIANT GetValue();
	void SetValue(const VARIANT& newValue);
	// method 'GetPrecision' not emitted because of invalid return type or parameter type
	// method 'GetNumericScale' not emitted because of invalid return type or parameter type
	void AppendChunk(const VARIANT& Data);
	VARIANT GetChunk(long Length);
	VARIANT GetOriginalValue();
	VARIANT GetUnderlyingValue();
	LPUNKNOWN GetDataFormat();
	void SetRefDataFormat(LPUNKNOWN newValue);
	// method 'SetPrecision' not emitted because of invalid return type or parameter type
	// method 'SetNumericScale' not emitted because of invalid return type or parameter type
	void SetType(long nNewValue);
	void SetDefinedSize(long nNewValue);
	void SetAttributes(long nNewValue);
	long GetStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIELD_H__17A4856A_3263_4CC3_BAD8_A960AE60369E__INCLUDED_)
