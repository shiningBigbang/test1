
// AdditionDlg.h: 头文件
//

#pragma once
#include "resource.h"
#include "CTipDlg.h"
#define WM_MyMessage WM_USER+100



// CAdditionDlg 对话框
class CAdditionDlg : public CDialogEx
{
// 构造
public:
	CAdditionDlg(CWnd* pParent = nullptr);
	// 标准构造函数
	~CAdditionDlg();
	//添加析构函数声明
private:	
	CTipDlg  *m_pTipDlg;
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADDITION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);//自己添加的消息函数
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedSumStatic();
	double m_editSummand;
	double m_editAddend;
	double m_editSum;
	afx_msg void OnBnClickedAddButton();
};
