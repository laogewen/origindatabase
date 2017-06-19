
// MFC_DBDlg.h : 头文件
//

#pragma once
#include <string>
#include <vector>
#include <stdio.h>  
#include "afxcmn.h"
#include "afxwin.h"

typedef struct _STUDENT_INFO
	{
		char ID[32];
		char Name[16];
		double Score[3];
		struct _STUDENT_INFO *next;
	}STUDENT_INFO;



// CMFC_DBDlg 对话框
class CMFC_DBDlg : public CDialogEx
{
// 构造
public:
	CMFC_DBDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_DB_DIALOG };

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
	DECLARE_MESSAGE_MAP()



public:
	afx_msg void OnBnClickedButtonFileload();
public:
	std::vector<STUDENT_INFO> vecSTDINFO;
	std::vector<STUDENT_INFO> it;
	CListCtrl myLIST_ShowInfo;
	afx_msg void OnNMRClickListShowinfo(NMHDR *pNMHDR, LRESULT *pResult);
	void Vector_Traverse(std::vector<STUDENT_INFO> vec);
	afx_msg void OnBnClickedButtonNewnode();
	CEdit score1;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonsort();
	afx_msg void OnBnClickedOk();
	afx_msg void OnHdnItemclickListShowinfo(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkListShowinfo(NMHDR *pNMHDR, LRESULT *pResult);
	CEdit m_edit;
	afx_msg void OnEnKillfocusEditName6();
	CEdit s_edit;
};
