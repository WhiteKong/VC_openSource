; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPrintWordsDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PrintWords.h"

ClassCount=3
Class1=CPrintWordsApp
Class2=CPrintWordsDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_PRINTWORDS_DIALOG

[CLS:CPrintWordsApp]
Type=0
HeaderFile=PrintWords.h
ImplementationFile=PrintWords.cpp
Filter=N

[CLS:CPrintWordsDlg]
Type=0
HeaderFile=PrintWordsDlg.h
ImplementationFile=PrintWordsDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=PrintWordsDlg.h
ImplementationFile=PrintWordsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PRINTWORDS_DIALOG]
Type=1
Class=CPrintWordsDlg
ControlCount=4
Control1=IDC_LIST1,listbox,1352728835
Control2=IDC_BUTLIULAN,button,1342242816
Control3=IDC_BUTPRINT,button,1342242816
Control4=IDC_STATIC,static,1342308352

