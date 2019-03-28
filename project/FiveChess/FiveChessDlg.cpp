
// FiveChessDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "FiveChess.h"
#include "FiveChessDlg.h"
#include "afxdialogex.h"

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


// CFiveChessDlg 对话框



CFiveChessDlg::CFiveChessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FIVECHESS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFiveChessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFiveChessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_NEW_GAME_MENU, &CFiveChessDlg::OnNewGameMenu)
	ON_COMMAND(ID_EXIT_GAME_MENU, &CFiveChessDlg::OnExitGameMenu)
	ON_COMMAND(ID_DRAW_GAME_MENU, &CFiveChessDlg::OnDrawGameMenu)
	ON_BN_CLICKED(IDCANCEL, &CFiveChessDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CFiveChessDlg 消息处理程序

BOOL CFiveChessDlg::OnInitDialog()
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

	m_main_menu.LoadMenu(IDR_MAIN_MENU);

	SetMenu(&m_main_menu);

	m_main_menu.EnableMenuItem(ID_DRAW_GAME_MENU, MF_GRAYED | MF_DISABLED);

	m_bIsConnect = FALSE;

	CRect rect(0, 0, 200, 200);
	m_board.CreateEx(WS_EX_CLIENTEDGE, _T("ChessBoard"), NULL, WS_VISIBLE | WS_BORDER | WS_CHILD,
		CRect(0, 0, 401, 478), this, IDC_BOARD);
	//清空棋盘
	m_board.Clear(TRUE);

	GetDlgItem(IDC_BOARD)->SetFocus();

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CFiveChessDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFiveChessDlg::OnPaint()
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
HCURSOR CFiveChessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFiveChessDlg::OnNewGameMenu()
{
	// TODO: 在此添加命令处理程序代码
	if (IDOK == m_setup_dlg.DoModal())
	{
		Restart();
		NewGameStart(m_setup_dlg.m_isHost);
	}

}


void CFiveChessDlg::OnExitGameMenu()
{
	// TODO: 在此添加命令处理程序代码
	SetMenu(NULL);
	CDialog::OnCancel();
}


void CFiveChessDlg::OnDrawGameMenu()
{
	// TODO: 在此添加命令处理程序代码
	if (m_bIsConnect)
	{
		m_board.DrawGame();
	}
}

void CFiveChessDlg::Restart()
{
	m_conncet.Close();
	m_sock.Close();
}

void CFiveChessDlg::NewGameStart(BOOL isHost)
{
	if (isHost)
	{//当前选择的是主机
		m_conncet.Create(m_setup_dlg.m_net_port);	//建立端口对象
		m_conncet.Listen();							//监听
	}
	else
	{//当前选择的是客户机
		m_sock.Create();							//建立端口对象
													//建立连接
		m_sock.Connect(m_setup_dlg.m_strHostIP, m_setup_dlg.m_net_port);
	}
}

void CFiveChessDlg::Accept()
{
	//接受连接
	m_conncet.Accept(m_sock);
	//设置连接成功标志
	m_bIsConnect = TRUE;
	//设置当前棋子颜色
	m_board.SetColor(BLACK);
	m_board.Clear(FALSE);
	//弹出提示对话框
	MessageBox(_T("连接成功,可以开始游戏."), _T("五子棋"), MB_ICONINFORMATION);
}

void CFiveChessDlg::Connect()
{
	//设置连接成功标志
	m_bIsConnect = TRUE;
	//设置当前棋子颜色
	m_board.SetColor(WHITE);
	m_board.Clear(TRUE);
	//弹出提示对话框
	MessageBox(_T("连接成功,可以开始游戏."), _T("五子棋"), MB_ICONINFORMATION);
}

void CFiveChessDlg::Send(MSGSTRUCT * pmsg)
{
	m_sock.Send((LPVOID)pmsg, sizeof(MSGSTRUCT));
}

void CFiveChessDlg::SetMenuState(BOOL bEnable)
{
	UINT uEnable, uDisable;
	if (bEnable)
	{
		uEnable = MF_ENABLED;
		uDisable = MF_GRAYED | MF_DISABLED;
	}
	else
	{
		uEnable = MF_GRAYED | MF_DISABLED;
		uDisable = MF_ENABLED;
	}

	m_main_menu.EnableMenuItem(ID_NEW_GAME_MENU, uEnable);
	m_main_menu.EnableMenuItem(ID_DRAW_GAME_MENU, uDisable);
}


void CFiveChessDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
