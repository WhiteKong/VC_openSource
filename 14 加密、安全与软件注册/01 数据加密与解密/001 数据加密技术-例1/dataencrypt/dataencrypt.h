// dataencrypt.h : main header file for the DATAENCRYPT application
//

#if !defined(AFX_DATAENCRYPT_H__A82D75B9_A156_4AF6_A936_28EDB54850F7__INCLUDED_)
#define AFX_DATAENCRYPT_H__A82D75B9_A156_4AF6_A936_28EDB54850F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDataencryptApp:
// See dataencrypt.cpp for the implementation of this class
//

class CDataencryptApp : public CWinApp
{
public:
	CDataencryptApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataencryptApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDataencryptApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATAENCRYPT_H__A82D75B9_A156_4AF6_A936_28EDB54850F7__INCLUDED_)
