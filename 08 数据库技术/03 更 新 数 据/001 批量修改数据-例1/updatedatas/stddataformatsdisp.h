#if !defined(AFX_STDDATAFORMATSDISP_H__673E9FA8_F250_46BC_BBC1_E822A7C9A028__INCLUDED_)
#define AFX_STDDATAFORMATSDISP_H__673E9FA8_F250_46BC_BBC1_E822A7C9A028__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CDataFormatDisp;

/////////////////////////////////////////////////////////////////////////////
// CStdDataFormatsDisp wrapper class

class CStdDataFormatsDisp : public COleDispatchDriver
{
public:
	CStdDataFormatsDisp() {}		// Calls COleDispatchDriver default constructor
	CStdDataFormatsDisp(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CStdDataFormatsDisp(const CStdDataFormatsDisp& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	CDataFormatDisp GetItem(const VARIANT& Index);
	void Add(LPDISPATCH pFormat, const VARIANT& Index);
	void Remove(const VARIANT& Index);
	void Clear();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDDATAFORMATSDISP_H__673E9FA8_F250_46BC_BBC1_E822A7C9A028__INCLUDED_)
