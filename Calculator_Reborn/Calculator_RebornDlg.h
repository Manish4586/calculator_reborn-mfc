
// Calculator_RebornDlg.h : header file
//

#pragma once


// CCalculator_RebornDlg dialog
class CCalculator_RebornDlg : public CDialogEx
{
// Construction
public:
	CCalculator_RebornDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CALCULATOR_REBORN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	bool flag;
	CString result;
	CString st1, st2;
	int op;
	double num0, num1, num2;
	afx_msg void OnButtonClicked(UINT nIDbutton);
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonPLUS();
	afx_msg void OnBnClickedButtonMIN();
	afx_msg void OnBnClickedButtonMUL();
	afx_msg void OnBnClickedButtonDIV();
	afx_msg void OnBnClickedButtonSQ();
	afx_msg void OnBnClickedButtonROOT();
	afx_msg void OnBnClickedButtonINV();
	afx_msg void OnBnClickedButtonDOT();
	afx_msg void OnBnClickedButtonC();
	afx_msg void OnBnClickedButtonBackSpace();
	afx_msg void OnBnClickedButtonEQ();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
