
// CalculatorGUIDlg.h : header file
//

#pragma once

#include <string>
#include <vector>

#include "COperatorHighlightEditBox.h"

using namespace std;


// CCalculatorGUIDlg dialog
class CCalculatorGUIDlg : public CDialogEx
{
// Construction
public:
	CCalculatorGUIDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATORGUI_DIALOG };
#endif

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
	afx_msg void OnBnClickedPlusButton();
	afx_msg void OnBnClickedMinusButton();
	afx_msg void OnBnClickedAnsButton();
	afx_msg void OnBnClickedButtonKey1();
	afx_msg void OnBnClickedButtonKey2();
	afx_msg void OnBnClickedButtonKey3();
	afx_msg void OnBnClickedButtonKey4();
	afx_msg void OnBnClickedButtonKey5();
	afx_msg void OnBnClickedButtonKey6();
	afx_msg void OnBnClickedButtonKey7();
	afx_msg void OnBnClickedButtonKey8();
	afx_msg void OnBnClickedButtonKey9();
	afx_msg void OnBnClickedButtonKey0();
public:
	bool noHandleMainEditTextChange;
public:
	string getMainEditText();
	void setMainEditText(string str);
	void refreshAllStrings();
	void setOutputStaticText(string str);
	void addToMainEditText(char ch);
	void moveMainEditTextCursorToEnd();
	afx_msg void OnBnClickedClearButton();
	afx_msg void OnBnClickedMultiplyButton();
	afx_msg void OnBnClickedDivideButton();
	afx_msg void onChangeMainEditText();
	afx_msg void onPressedEnter();

private:
	COperatorHighlightEditBox cOperatorHighlightEditBox;
};
