
// FiveChessDlg.h: 头文件
//
#include "CSetupDlg.h"
#include "CConnect.h"
#include "ConnectData.h"
#include "CBoard.h"

#pragma once


// CFiveChessDlg 对话框
class CFiveChessDlg : public CDialogEx
{
// 构造
public:
	CConnect m_conncet;			//监听套接字
	CConnect m_sock;			//使用套接字
	BOOL     m_bIsConnect;		//连接标志
	CBoard   m_board;			//主棋盘对象

	void NewGameStart(BOOL isHost);
	void SetMenuState(BOOL bEnable);		//设置菜单状态
	void Accept();							//服务器端口申请连接成功时调用
	void Connect();							//客户机申请连接成功调用
	void Send(MSGSTRUCT * pmsg);			//发送数据
	void Restart();							//重新开始游戏

	CFiveChessDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIVECHESS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CMenu m_main_menu;			//主菜单对象
	CSetupDlg m_setup_dlg;		//设置对话框对象


	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnNewGameMenu();
	afx_msg void OnExitGameMenu();
	afx_msg void OnDrawGameMenu();
public:
	afx_msg void OnBnClickedCancel();
};
