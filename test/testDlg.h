// testDlg.h : header file
//

#pragma once
#include "afxwin.h"

// CtestDlg dialog
class CtestDlg : public CDialog
{
// Construction
public:
	CtestDlg(CWnd* pParent = NULL);	// standard constructor
	void ChangeOffset(int add);
	void Decrypt();
	int state;
// Dialog Data
	enum { IDD = IDD_TEST_DIALOG_WIDE };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
//#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
//	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
//#endif
	DECLARE_MESSAGE_MAP()
public:
	CEdit text;
public:
	CEdit offset;
public:
	afx_msg void OnBnClickedButton3();
public:
	afx_msg void OnBnClickedButton2();
public:
	afx_msg void OnEnChangeEdit2();
public:
	afx_msg void OnBnClickedButton1();
public:
	CEdit alphabet;
};
