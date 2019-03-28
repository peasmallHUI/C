#pragma once
#include "stdafx.h"
#include "Resource.h"

// CSetupDlg 对话框

class CSetupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSetupDlg)

public:
	CSetupDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSetupDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETUP_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_isHost;
	CString m_strHostIP;

	CIPAddressCtrl m_ip_addr;
	UINT m_net_port;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnClientOption();
	afx_msg void OnHostOption();
	virtual BOOL OnInitDialog();
};
