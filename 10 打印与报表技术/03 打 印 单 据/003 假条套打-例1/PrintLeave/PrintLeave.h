// PrintLeave.h : main header file for the PRINTLEAVE application
//

#if !defined(AFX_PRINTLEAVE_H__F2DCD316_156A_4092_892C_D030CDCCA971__INCLUDED_)
#define AFX_PRINTLEAVE_H__F2DCD316_156A_4092_892C_D030CDCCA971__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintLeaveApp:
// See PrintLeave.cpp for the implementation of this class
//

class CPrintLeaveApp : public CWinApp
{
public:
	CPrintLeaveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintLeaveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrintLeaveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTLEAVE_H__F2DCD316_156A_4092_892C_D030CDCCA971__INCLUDED_)
