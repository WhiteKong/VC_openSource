#if !defined(AFX_SPLITS_H__A8D25DB6_7340_43E7_86D5_62407806C5B8__INCLUDED_)
#define AFX_SPLITS_H__A8D25DB6_7340_43E7_86D5_62407806C5B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CSplit;

/////////////////////////////////////////////////////////////////////////////
// CSplits wrapper class

class CSplits : public COleDispatchDriver
{
public:
	CSplits() {}		// Calls COleDispatchDriver default constructor
	CSplits(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSplits(const CSplits& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	CSplit GetItem(const VARIANT& Index);
	CSplit Add(short Index);
	void Remove(const VARIANT& Index);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITS_H__A8D25DB6_7340_43E7_86D5_62407806C5B8__INCLUDED_)
