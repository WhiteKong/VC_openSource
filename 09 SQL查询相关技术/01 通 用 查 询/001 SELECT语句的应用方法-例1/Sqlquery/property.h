#if !defined(AFX_PROPERTY_H__D8B106CD_6D92_4ACA_A1A0_C44CE38A3459__INCLUDED_)
#define AFX_PROPERTY_H__D8B106CD_6D92_4ACA_A1A0_C44CE38A3459__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CProperty wrapper class

class CProperty : public COleDispatchDriver
{
public:
	CProperty() {}		// Calls COleDispatchDriver default constructor
	CProperty(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CProperty(const CProperty& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	VARIANT GetValue();
	void SetValue(const VARIANT& newValue);
	CString GetName();
	long GetType();
	long GetAttributes();
	void SetAttributes(long nNewValue);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTY_H__D8B106CD_6D92_4ACA_A1A0_C44CE38A3459__INCLUDED_)
