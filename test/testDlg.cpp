// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CtestDlg dialog

CtestDlg::CtestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CtestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text);
	DDX_Control(pDX, IDC_EDIT2, offset);
	DDX_Control(pDX, IDC_EDIT3, alphabet);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON3, &CtestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CtestDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CtestDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &CtestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtestDlg message handlers

BOOL CtestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CString temp;
	temp="0";
	offset.SetWindowTextW(temp);
	temp="abcdefghijklmnopqrstuvwxyz";
	alphabet.SetWindowTextW(temp);
	state=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
//void CtestDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
/*{
	DRA::RelayoutDialog(
		AfxGetInstanceHandle(), 
		this->m_hWnd, 
		DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_TEST_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_TEST_DIALOG));
}
#endif
*/

void CtestDlg::OnBnClickedButton3()
{
	ChangeOffset(1);
}

void CtestDlg::OnBnClickedButton2()
{
	ChangeOffset(-1);
}

void CtestDlg::ChangeOffset(int add)
{
	CString temp;
	offset.GetWindowTextW(temp);
	int NewState=(int)_wcstoi64(temp.GetBuffer(),NULL,10)+add;
	temp="%i";
	temp.Format(temp,NewState);
	offset.SetWindowTextW(temp);
}
void CtestDlg::OnEnChangeEdit2()
{
	Decrypt();
}

void CtestDlg::Decrypt()
{
	CString temp,Alph;
	alphabet.GetWindowTextW(Alph);
	offset.GetWindowTextW(temp);
	int NewState=(int)_wcstoi64(temp.GetBuffer(),NULL,10);
	text.GetWindowTextW(temp);
	for(int i=0;i<temp.GetLength();i++)
	{
		int c=Alph.Find(temp[i]);
		if(c!=-1)
		{
			c+=NewState-state;
			if(c<0)
				c+=Alph.GetLength();
			temp.SetAt(i,Alph[c%Alph.GetLength()]);
		}
	}
	state=NewState;
	text.SetWindowTextW(temp);
}

void CtestDlg::OnBnClickedButton1()
{
	CString temp,Alph;
	text.GetWindowTextW(temp);
	int * l=new int[255];
	for(int i=0;i<255;i++)
		l[i]=0;
	for(int i=0;i<temp.GetLength();i++)
		l[temp[i]]++;
	int max=0;
	int cur=0;
	for(int i=0;i<255;i++)
	{
		if(max<l[i])
		{
			max=l[i];
			cur=i;
		}
	}
	alphabet.GetWindowTextW(Alph);
	int add=Alph.Find(' ')-Alph.Find(cur);
	ChangeOffset(add);
}
																																	