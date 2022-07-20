
// AdditionDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Addition.h"
#include "AdditionDlg.h"
#include "afxdialogex.h"
//#include "CTipDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAdditionDlg 对话框



CAdditionDlg::CAdditionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDITION_DIALOG, pParent)
	, m_editSummand(0)
	, m_editAddend(0)
	, m_editSum(0)
	, m_pTipDlg(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}



void CAdditionDlg::DoDataExchange(CDataExchange* pDX)
{
	// 处理MFC默认的数据交换  
	CDialogEx::DoDataExchange(pDX);
	// 处理控件IDC_SUMMAND_EDIT和变量m_editSummand之间的数据交换 
	DDX_Text(pDX, IDC_SUMMAND_EDIT, m_editSummand);
	// 处理控件IDC_ADDEND_EDIT和变量m_editAddend之间的数据交换
	DDX_Text(pDX, IDC_ADDEND_EDIT, m_editAddend);
	// 处理控件IDC_SUM_EDIT和变量m_editSum之间的数据交换 
	DDX_Text(pDX, IDC_SUM_EDIT, m_editSum);
}



BEGIN_MESSAGE_MAP(CAdditionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_MyMessage, &CAdditionDlg::OnMyMessage)
	ON_BN_CLICKED(IDC_ADD_BUTTON, &CAdditionDlg::OnBnClickedAddButton)
END_MESSAGE_MAP()


// CAdditionDlg 消息处理程序

BOOL CAdditionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAdditionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAdditionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAdditionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAdditionDlg::OnBnClickedAddButton()
{
	/*INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	CTipDlg tipDlg;           // 构造对话框类CTipDlg的实例   
	nRes = tipDlg.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		return;*/

	// 如果指针变量m_pTipDlg的值为NULL，则对话框还未创建，需要动态创建
		if (NULL == m_pTipDlg)
		{
			// 创建非模态对话框实例   
			m_pTipDlg = new CTipDlg();
			m_pTipDlg->Create(IDD_TIP_DIALOG, this); //创建窗口
		}
	// 显示非模态对话框   
	m_pTipDlg->ShowWindow(SW_SHOW);  //显示窗口
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);//自己添加的消息函数
	/*
	// TODO: 在此添加控件通知处理程序代码
	// 将各控件中的数据保存到相应的变量   
	UpdateData(TRUE);

	// 将被加数和加数的加和赋值给m_editSum   
	m_editSum = m_editSummand + m_editAddend;

	// 根据各变量的值更新相应的控件。和的编辑框会显示m_editSum的值   
	UpdateData(FALSE);
	*/
}

CAdditionDlg::~CAdditionDlg()
{
	// 如果非模态对话框已经创建则删除它   
	if (NULL != m_pTipDlg)
	{
		// 删除非模态对话框对象   
		delete m_pTipDlg;
	}
}


void CAboutDlg::OnBnClickedOk()
{

	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	::SendMessage(this->GetParent()->m_hWnd, WM_MyMessage, 0, 0);

}

LRESULT CAdditionDlg::OnMyMessage(WPARAM wParam, LPARAM IParam)
{
	UpdateData(TRUE);

	// 将被加数和加数的加和赋值给m_editSum   
	m_editSum = m_editSummand + m_editAddend;

	// 根据各变量的值更新相应的控件。和的编辑框会显示m_editSum的值   
	UpdateData(FALSE);
	return 0;
}