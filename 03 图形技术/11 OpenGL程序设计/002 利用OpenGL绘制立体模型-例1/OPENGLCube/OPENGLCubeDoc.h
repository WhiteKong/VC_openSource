// OPENGLCubeDoc.h : interface of the COPENGLCubeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLCUBEDOC_H__20B55B6F_3DC6_44B9_A005_7225898DA56E__INCLUDED_)
#define AFX_OPENGLCUBEDOC_H__20B55B6F_3DC6_44B9_A005_7225898DA56E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COPENGLCubeDoc : public CDocument
{
protected: // create from serialization only
	COPENGLCubeDoc();
	DECLARE_DYNCREATE(COPENGLCubeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COPENGLCubeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COPENGLCubeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COPENGLCubeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLCUBEDOC_H__20B55B6F_3DC6_44B9_A005_7225898DA56E__INCLUDED_)
