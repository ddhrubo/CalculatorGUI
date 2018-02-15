
// CalculatorGUIDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CalculatorGUI.h"
#include "CalculatorGUIDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorGUIDlg dialog



CCalculatorGUIDlg::CCalculatorGUIDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATORGUI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalculatorGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_EN_CHANGE(MAIN_EDIT_BOX, &CCalculatorGUIDlg::onChangeMainEditText)
	ON_COMMAND(IDOK, &CCalculatorGUIDlg::onPressedEnter)

	ON_BN_CLICKED(IDC_PLUS_BUTTON, &CCalculatorGUIDlg::OnBnClickedPlusButton)
	ON_BN_CLICKED(IDC_MINUS_BUTTON, &CCalculatorGUIDlg::OnBnClickedMinusButton)
	ON_BN_CLICKED(IDC_ANS_BUTTON, &CCalculatorGUIDlg::OnBnClickedAnsButton)
	ON_BN_CLICKED(IDC_BUTTON_KEY_1, &CCalculatorGUIDlg::OnBnClickedButtonKey1)

	ON_BN_CLICKED(IDC_BUTTON_KEY_2, &CCalculatorGUIDlg::OnBnClickedButtonKey2)
	ON_BN_CLICKED(IDC_BUTTON_KEY_3, &CCalculatorGUIDlg::OnBnClickedButtonKey3)
	ON_BN_CLICKED(IDC_BUTTON_KEY_4, &CCalculatorGUIDlg::OnBnClickedButtonKey4)
	ON_BN_CLICKED(IDC_BUTTON_KEY_5, &CCalculatorGUIDlg::OnBnClickedButtonKey5)
	ON_BN_CLICKED(IDC_BUTTON_KEY_6, &CCalculatorGUIDlg::OnBnClickedButtonKey6)
	ON_BN_CLICKED(IDC_BUTTON_KEY_7, &CCalculatorGUIDlg::OnBnClickedButtonKey7)
	ON_BN_CLICKED(IDC_BUTTON_KEY_8, &CCalculatorGUIDlg::OnBnClickedButtonKey8)
	ON_BN_CLICKED(IDC_BUTTON_KEY_9, &CCalculatorGUIDlg::OnBnClickedButtonKey9)
	ON_BN_CLICKED(IDC_BUTTON_KEY_0, &CCalculatorGUIDlg::OnBnClickedButtonKey0)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CCalculatorGUIDlg::OnBnClickedClearButton)
	ON_BN_CLICKED(IDC_MULTIPLY_BUTTON, &CCalculatorGUIDlg::OnBnClickedMultiplyButton)
	ON_BN_CLICKED(IDC_DIVIDE_BUTTON, &CCalculatorGUIDlg::OnBnClickedDivideButton)
END_MESSAGE_MAP()

//DECLARE_DYNAMIC(COperatorHighlightEditBox)

// CCalculatorGUIDlg message handlers

BOOL CCalculatorGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	cOperatorHighlightEditBox.SubclassDlgItem(MAIN_EDIT_BOX, this);
	refreshAllStrings();

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

void CCalculatorGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorGUIDlg::OnPaint()
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
HCURSOR CCalculatorGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

