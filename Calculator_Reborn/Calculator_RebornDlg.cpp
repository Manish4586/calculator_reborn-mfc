
// Calculator_RebornDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator_Reborn.h"
#include "Calculator_RebornDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
    //afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculator_RebornDlg dialog




CCalculator_RebornDlg::CCalculator_RebornDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculator_RebornDlg::IDD, pParent), /*Declare it*/ result(_T(""))

{
	// Add By Manish4586 @20230920
	num0 = num1 = num2 = 0;
	st1 = _T("");
	st2 = _T("");
	flag = true;
	op = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculator_RebornDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISP, result);
}

BEGIN_MESSAGE_MAP(CCalculator_RebornDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	// Add By Manish4586 @20230921 for bg color
	//ON_WM_ERASEBKGND()
	//ON_WM_CTLCOLOR()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON1, IDC_BUTTON9, OnButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON0, &CCalculator_RebornDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTONPLUS, &CCalculator_RebornDlg::OnBnClickedButtonPLUS)
	ON_BN_CLICKED(IDC_BUTTONMIN, &CCalculator_RebornDlg::OnBnClickedButtonMIN)
	ON_BN_CLICKED(IDC_BUTTONMUL, &CCalculator_RebornDlg::OnBnClickedButtonMUL)
	ON_BN_CLICKED(IDC_BUTTONDIV, &CCalculator_RebornDlg::OnBnClickedButtonDIV)
	ON_BN_CLICKED(IDC_BUTTONSQ, &CCalculator_RebornDlg::OnBnClickedButtonSQ)
	ON_BN_CLICKED(IDC_BUTTONROOT, &CCalculator_RebornDlg::OnBnClickedButtonROOT)
	ON_BN_CLICKED(IDC_BUTTONINV, &CCalculator_RebornDlg::OnBnClickedButtonINV)
	ON_BN_CLICKED(IDC_BUTTONDOT, &CCalculator_RebornDlg::OnBnClickedButtonDOT)
	ON_BN_CLICKED(IDC_BUTTONC, &CCalculator_RebornDlg::OnBnClickedButtonC)
	ON_BN_CLICKED(IDC_BUTTONBACK, &CCalculator_RebornDlg::OnBnClickedButtonBackSpace)
	ON_BN_CLICKED(IDC_BUTTONEQ, &CCalculator_RebornDlg::OnBnClickedButtonEQ)
END_MESSAGE_MAP()


// CCalculator_RebornDlg message handlers

BOOL CCalculator_RebornDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculator_RebornDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculator_RebornDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculator_RebornDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Add for Calculator_Reborn @20230922
// Reborn Edition of Normal test variant calculator
// expands the features of my test build calculator
//here im trying to replicate this version with an actual calculator.

void CCalculator_RebornDlg::OnButtonClicked(UINT nID)
{
	char ch = '0' + nID - IDC_BUTTON0;
	if (flag == true)
	{
		if (st1.GetLength()<=15)
		{
        /*	if(result.Find(_T(".")))
		{
			st1 = result +CString(ch);
		}
		else
		{*/
		st1 += CString(ch);
		//}
		result = st1;
		}
		else
		{  	
			AfxMessageBox(_T("Calculator ????")); 
		}
	}
	else if (flag == false)
	{
	if (st2.GetLength()<=15)
		{
			/*if(result.Find(L"."))
		{
			st2 = result + CString(ch);
		}
		else
		{*/
		st2 += CString(ch);
		//}
		result = st2;
	    }
	else
		{  	
			AfxMessageBox(_T("sorry!!!")); 
	    }
	}
	UpdateData(false);
}

// fix unnecessary zero @20230928
void CCalculator_RebornDlg::OnBnClickedButton0()
{
	if (flag == true)
	{ 
 if (st1.GetLength()<=15)
	{ 
		if (st1!= _T("0"))
		{
		    st1 += _T("0");
		}
		else
		{
			st1 = _T("0");
		}
		result = st1;
	}
	else
		{  	
			AfxMessageBox(_T("Calculator ????")); 
		}
	}
	else if (flag == false)
	{
 if (st2.GetLength()<=15)
	{
		if (st2!= _T("0"))
		{
		    st2 += _T("0");
		}
		else
		{
			st2 = _T("0");
	 }
	}
	 	else
		{  	
			AfxMessageBox(_T("no?")); 
		}
		result = st2;
	}
	UpdateData(false);
}

void CCalculator_RebornDlg::OnBnClickedButtonPLUS()
{
	 /*if (!st1.IsEmpty() && !st2.IsEmpty())
	{

		num1 = _ttof(st1);
		num2 = _ttof(st2);
		num1 = num1 + num2;
		
	
		result.Format(_T("%0.f "), num1);
		num2 = num1 = 0;
		st1 = _T("");
		st2 = _T("");
	 }
	else */if (result!= _T(""))
	{
		num1 = _ttof(result);
	    flag = !flag;
		// Add By Manish4586 @20230921 lets display operand
		result.Format(_T("%0.f + "), num1); // Append " + " to the display string.
		//E_result = _T("");
	    op = 1;
		//st1.Format(_T("%0.f +"), num1);
	}
	    
		UpdateData(false);
}

void CCalculator_RebornDlg::OnBnClickedButtonMIN()
{
	if (result!= _T(""))
	{
		num1 = _ttof(result);
	    flag = !flag;
		// Add By Manish4586 @20230921 lets display operand
		result.Format(_T("%0.f - "), num1); // Append " + " to the display string.
		//E_result = _T("");
	    op = 2;
	}
		UpdateData(false);
}

void CCalculator_RebornDlg::OnBnClickedButtonMUL()
{
	if (result!= _T(""))
	{
		num1 = _ttof(result);
	    flag = !flag;
		// Add By Manish4586 @20230921 lets display operand
		result.Format(_T("%0.f * "), num1); // Append " + " to the display string.
		//E_result = _T("");
	    op = 3;
		
	}
		UpdateData(false);
}

void CCalculator_RebornDlg::OnBnClickedButtonDIV()
{
	if (result!= _T(""))
	{
		num1 = _ttof(result);
	    flag = !flag;
		// Add By Manish4586 @20230921 lets display operand
		result.Format(_T("%0.f / "), num1); // Append " + " to the display string.
		//E_result = _T("");
	    op = 4;
	}
		UpdateData(false);
}

void CCalculator_RebornDlg::OnBnClickedButtonSQ()
{
	if (result!= _T(""))
	{
		num1 = _ttof(result);
		num0 = num1 * num1;
	}
	st1 = _T("");
	st2 = _T("");
	result.Format(_T("%0.f"), num0);
	UpdateData(false);
}

void CCalculator_RebornDlg::OnBnClickedButtonROOT()
{
	if (result!= _T(""))
	{
		num1 = _ttof(result);
		num0 = sqrt(num1);
	}
	st1 = _T("");
	st2 = _T("");
	// Add Condition for digits after '.' @20230926
	int t= result.GetLength();
	// End Condition for digits after '.' @20230926
	result.Format(_T("%f"), num0);
	// Add Condition for digits after '.' @20230926
	int n = result.Find(L".");
	char j = result.GetAt(n+2);
	int l = j - '0';
	if(l>=1 && l<=9)
	{
		result = result.Mid(0,n+6);
	}
	else
	{
	    result = result.Mid(0,n);
	}
	// End Condition for digits after '.' @20230926
	UpdateData(false);
}

void CCalculator_RebornDlg::OnBnClickedButtonINV()
{
    if (result != _T(""))
    {
        num1 = _ttof(result);
        num0 = 1 / num1;
    }
    st1 = _T("");
    st2 = _T("");
    
	CString str = _T("");
    result.Format(_T("%.15f"), num0);
	CString nw = _T("");
	nw.Format(_T("%g"), num0);
	int l = result.FindOneOf(L"23456789"); // predefining the values and searching them in result. @20230927
	//str.Format(_T("%g"), num0);
    //int t = result.GetLength();
   //int n = result.Find(L".");
	if(l != -1)
	{
	int q = nw.Find(L"e");
	if (q != -1)
    {
       result.Format(_T("%g"), num0);
    }
	}
	else 
	{
		while (result.GetLength() > 2 && result.Right(1) == _T("0"))
    {
        result = result.Left(result.GetLength() - 1);
    }
	}
	UpdateData(false);
}


// Add for appending '.' function @20230925
void CCalculator_RebornDlg::OnBnClickedButtonDOT()
{
	if (result!= _T(""))
	{
	    flag = !flag;
		result.Format(_T("%s."), result);
	}
		UpdateData(false);
}

void CCalculator_RebornDlg::OnBnClickedButtonC()
{
  if(result!= _T(""))
 {
	num0 = num1 = num2 = 0;
	st1 = _T("");
	st2 = _T("");
  }
	result.Format(_T(""), num0);
	UpdateData(false);
}

// Add For Backspace @20230925
void CCalculator_RebornDlg::OnBnClickedButtonBackSpace()
{
	if(op == 0)
	{
	if (!st1.IsEmpty())
	{
	st1= st1.Mid(0, st1.GetLength() -1);
	num1 = _ttof(st1);
	result.Format(_T("%.f"), num1);
	}
	}
	//fixup backspace for second number @20230928
	else if(op ==1 || op ==2 || op ==3 || op ==4)
	{
    if (!st2.IsEmpty())
	{
	st2= st2.Mid(0, st2.GetLength() -1);
	num2 = _ttof(st2);
	result.Format(_T("%.f"), num2);
	if ((num2 == 0) && (op ==1 || op ==2 || op ==3 || op ==4))
	 { 
		num1 = _ttof(st1);
		switch (op)
		 {
			case (1):
		result.Format(_T("%.f +"), num1);
		break;

			case (2):
		result.Format(_T("%.f -"), num1);
		break;

			case (3):
		result.Format(_T("%.f *"), num1);
		break;

			case (4):
		result.Format(_T("%.f /"), num1);
		break;
		 }

       }
    }
}
 /*
 // Trying To adapt backspace for results @20230926
 if(result!= _T(""))
 {(st1.GetLength()<=15) 
	num0 = num1 = num2 = 0;
	st1 = _T("");
	st2 = _T("");
  }*/
	UpdateData(false);
}

void CCalculator_RebornDlg::OnBnClickedButtonEQ()
{
	if (result != _T(""))
	{
		num2 = _ttof(result);
		result = _T("");
	}

    if (op == 1)
	{
		num0 = num1 + num2;
	}

	else if (op == 2)
	{
		num0 = num1 - num2;
	}

	else if (op == 3)
	{
		num0 = num1 * num2;
	}
	else if (op == 4)
	{ 
	     if(num2 == 0)
		  { 
			  AfxMessageBox(_T("Result is undefined."));
		   }
		  else if (num2 == 0)
		   { 
			  num0 = num1 / num1;
		   }
		  else
		   {
		      num0 = num1 / num2;
		   }
	}
	// Empty input strings - fixes number wrapping. @20230925
	st1 = _T("");
	st2 = _T("");

	if (op == 4) 
	{   
		// Add condition for Division to determine the output value @20230926
	    CString temp;
        double p = num0;
        temp.Format(_T("%f"), p);
		int t= temp.GetLength();
		int n = temp.Find(L".");
		char k = temp.GetAt(n+1);
	    char j = temp.GetAt(n+2);
	    int l = j - '0';
		int i = k - '0';
	  if(l>=1 && l<=9)
	    {
	    	result = temp.Mid(0,n+3);
	    }
	  else if (i>=1 && i<=9)
	    {
		    result = temp.Mid(0,n+2);
	    }
	  else
	    {
	        result = temp.Mid(0,n);
	    }
	  // End Condition for Division @20230926
	}
 	else
	{ 
		result.Format(_T("%0.f"), num0);
	}
	UpdateData(false);
}

// End Calculator_Reborn @20230922


// temp exclude colors. looks real ugly @20230927
/*HBRUSH CCalculator_RebornDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (pWnd->GetDlgCtrlID())
	{

	case IDC_BUTTONPLUS:
		hbr = CreateSolidBrush(RGB(255, 0, 0));
		break;

	case IDC_BUTTONMIN:
		hbr = CreateSolidBrush(RGB(80, 165, 130));
		break;

	case IDC_BUTTONEQ:
		hbr = CreateSolidBrush(RGB(255, 30, 15));
		break;

	case IDC_BUTTONMUL:
		hbr = CreateSolidBrush(RGB(255, 255, 0));
		break;

	case IDC_BUTTONDIV:
		hbr = CreateSolidBrush(RGB(255, 255, 0));
		break;

	case IDC_BUTTONC:
		hbr = CreateSolidBrush(RGB(255, 255, 0));
		break;

	case IDC_DISP:
		hbr = CreateSolidBrush(RGB(255, 255, 255));
		break;

	default:
		hbr = CreateSolidBrush(RGB(0, 125, 125));
		break;
	}

	return hbr;
}

// Add Background Color Properties by Manish4586 @20230921 
BOOL CCalculator_RebornDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	pDC->FillSolidRect(rect, RGB(9.8, 35.76, 50.69));

	return TRUE;
}
// End Background & Btn Color Properties by Manish4586 @20230921
*/
