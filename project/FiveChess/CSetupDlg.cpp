// CSetupDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "FiveChess.h"
#include "CSetupDlg.h"
#include "afxdialogex.h"


// CSetupDlg 对话框

IMPLEMENT_DYNAMIC(CSetupDlg, CDialogEx)

CSetupDlg::CSetupDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETUP_DLG, pParent)
	, m_net_port(0),m_isHost(FALSE)
{

}

CSetupDlg::~CSetupDlg()
{
}

void CSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IP_ADDRESS_EDIT, m_ip_addr);
	DDX_Text(pDX, IDC_NET_PORT_EDIT, m_net_port);
	DDV_MinMaxUInt(pDX, m_net_port, 1, 65535);
}


BEGIN_MESSAGE_MAP(CSetupDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CSetupDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CSetupDlg::OnBnClickedOk)
	ON_COMMAND(IDC_CLIENT_OPTION, &CSetupDlg::OnClientOption)
	ON_COMMAND(IDC_HOST_OPTION, &CSetupDlg::OnHostOption)
END_MESSAGE_MAP()


// CSetupDlg 消息处理程序


void CSetupDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CSetupDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strIP, strPort;

	UpdateData(TRUE);
	m_ip_addr.GetWindowText(strIP);
	m_strHostIP = strIP;
	strPort.Format(_T("%d"), m_net_port);
	if (m_isHost)
	{
		WritePrivateProfileString(_T("HOST"), _T("PORT"), strPort, _T(".\\config.ini"));
	}
	else
	{
		WritePrivateProfileString(_T("CLIENT"), _T("IP"), strIP, _T(".\\config.ini"));
		WritePrivateProfileString(_T("CLIENT"), _T("PORT"), strPort, _T(".\\config.ini"));
	}

	CDialogEx::OnOK();
}


void CSetupDlg::OnClientOption()
{
	// TODO: 在此添加命令处理程序代码
	char str[128] = { 0 };
	m_ip_addr.EnableWindow(TRUE);
	GetPrivateProfileString(_T("CLIENT"), _T("IP"), _T(""), (LPWSTR)str, 127, _T(".\\config.ini"));
	m_ip_addr.SetWindowText((LPCTSTR)str);
	memset(str, 0, 128);
	GetPrivateProfileString(_T("CLIENT"), _T("PORT"), _T("5000"), (LPWSTR)str, 127, _T(".\\config.ini"));
	m_net_port = atoi(str);
	m_isHost = FALSE;
	UpdateData(FALSE);
}


void CSetupDlg::OnHostOption()
{
	// TODO: 在此添加命令处理程序代码
	char str[128] = { 0 };
	m_ip_addr.EnableWindow(FALSE);
	GetPrivateProfileString(_T("HOST"), _T("IP"), _T(""), (LPWSTR)str, 127, _T(".\\config.ini"));
	m_ip_addr.SetWindowText((LPCTSTR)str);
	memset(str, 0, 128);
	GetPrivateProfileString(_T("HOST"), _T("PORT"), _T("5000"), (LPWSTR)str, 127, _T(".\\config.ini"));
	m_net_port = atoi(str);
	m_isHost = TRUE;
	UpdateData(FALSE);
}


BOOL CSetupDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	((CButton*)GetDlgItem(IDC_HOST_OPTION))->SetCheck(1);
	OnHostOption();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
